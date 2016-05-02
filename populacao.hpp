// Classe Populacao - Contem uma lista de individuos e metodos para geracao de 
// populacao base e executar os acasalamentos
// Autor: Tarciso Pereira Martins Junior - PG Estatística - UFMG
// e-mail: tarciso.junior@gmail.com

#include <iostream>
#include <random>
#include "individuo.hpp";
#include "individuo.cpp";

class Populacao {
    public:
	Individuo *pop;
	int tam, tamBase;
	float mediaG, dpG, mediaE, dpE;
	public:
	Populacao(void);
	Populacao(int tamanho);
	~Populacao(void);
	
	int geraPopulacaoBase(float media, float desvioPadrao);
	int geraPopulacaoBase(int tamanho, float mediaVG, float dpVG, float mediaEA, float dpEA);
	int ordena(int campoOrdem);
	int ordena_desc(int campoOrdem);
	int geraProgenie(int nMachos, int nFemeas, int nGeracoes, int selecao);
	void imprime(FILE *saida);
	void imprime_csv(FILE *saida);
	
	Individuo getIndividuo(int pos);
	Populacao filtraValor(int campo, int valor);
	Populacao filtraValor(int campo, int valor, int qtde);
	
};
