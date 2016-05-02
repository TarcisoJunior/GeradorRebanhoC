// Programa para gerar valores simulados para uma população
// Autor: Tarciso Pereira Martins Junior - PG Estatística - UFMG
// e-mail: tarciso.junior@gmail.com

#include <stdio.h>
#include <math.h>
#include "populacao.hpp"
#include "populacao.cpp"

int main(int argc, char **argv){
	
	//inicia configuracoes 
    int tamBase = (argc>2)?atoi(argv[1]): 30;
    int nGeracoes = (argc>3)?atoi(argv[2]): 5;
    int nMachos = (argc>4)?atoi(argv[3]): 2;
    int nFemeas = (argc>5)?atoi(argv[4]): 4;
    int tamTotal = int(tamBase + (nFemeas * nGeracoes));
    
    // 1-valor genetico; 2-valor de efeito de ambiente; 3-valor fenotipico
    int selecao = (argc>6)?atoi(argv[5]): 3; 
    
	float mVGBase = (argc>7)?atof(argv[6]):0;
	float dpVGBase = (argc>8)?atof(argv[7]):1;
	float mVEBase = (argc>9)?atof(argv[8]):0;
	float dpVEBase = (argc>10)?atof(argv[9]):1;
    
    //cria um objeto tipo Populacao
	GeraPop::Populacao pop(tamTotal);

    // gera uma populacao base com tamanho e média e desvio padrão para valor genetico e de ambiente
	pop.geraPopulacaoBase(tamBase,mVGBase,dpVGBase,mVEBase,dpVEBase);

    // gera ciclos de acasalamento priorizando maiores valores do campo indicado para seleção
	pop.geraProgenie(nMachos,nFemeas,nGeracoes,selecao);

    //ordena população por ID
	pop.ordena(0);
	
	//imprime saída
	if ((argc>10)&&(atoi(argv[10])==1))
		pop.imprime_csv(stdout);
	else pop.imprime(stdout);
	
	return(0);
}



