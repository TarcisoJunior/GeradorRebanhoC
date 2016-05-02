Populacao::Populacao(){
	tam = 0;
}

Populacao::Populacao(int tamanho){
	tam = tamanho;
	pop = new Individuo[tam];
}

Populacao::~Populacao(void){
	//fprintf(stdout, "Populacao->destrutor");
	delete pop;
}

int Populacao::geraPopulacaoBase(float media, float desvioPadrao){
    std::default_random_engine generator;
	std::normal_distribution<double> distribution(media, desvioPadrao);

	for (int i=0; i<tam; i++){
		pop[i] = Individuo(i+1);
		pop[i].setValorGenetico(distribution(generator));
		pop[i].setSexo( rand() %2 +1);
	}

}

int Populacao::geraPopulacaoBase(int tamanho, float mediaVG, float dpVG, float mediaEA, float dpEA){
	tamBase = tamanho;
	mediaG = mediaVG;
    dpG = dpVG;
    mediaE = mediaEA;
    dpE = dpEA;
    
    std::default_random_engine generator;
	std::normal_distribution<double> distribution(mediaVG, dpVG);
	std::normal_distribution<float> environment(mediaEA, dpEA);

	for (int i=0; i<tamanho; i++){
		pop[i] = Individuo(i+1);
		pop[i].setValorGenetico(distribution(generator));
		pop[i].setValorAmbiente(environment(generator));
		pop[i].setSexo (rand() %2 +1 );
		pop[i].geracao = 1;
	}

}

Individuo Populacao::getIndividuo(int pos){
	return pop[pos];
}

// Ordena de acordo com o campo selecionado (1(vg), 2(ve), 3(vf), 4(sexo), 5(geracao))
int Populacao::ordena(int campoOrdem){
	bool trocar;
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam-1; j++){
			trocar = false;
			switch (campoOrdem) {
			  case 0: trocar = (pop[j].idIndividuo > pop[j+1].idIndividuo);
			          break;
			  case 1: trocar = (pop[j].vg > pop[j+1].vg);
			          break;
			  case 2: trocar = (pop[j].ve > pop[j+1].ve);
			  		  break;
			  case 3: trocar = (pop[j].vf > pop[j+1].vf);
			  		  break;
			  case 4: trocar = (pop[j].sexo > pop[j+1].sexo);
			  		  break;
			  case 5: trocar = (pop[j].geracao > pop[j+1].geracao);
			  		  break;
			}
			if (trocar){
				Individuo aux = pop[j+1];
				pop[j+1] = pop[j];
				pop[j] = aux;
			}
		}
	}
}

int Populacao::ordena_desc(int campoOrdem){
	bool trocar;
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam-1; j++){
			trocar = false;
			switch (campoOrdem) {
			  case 0: trocar = (pop[j].idIndividuo > pop[j+1].idIndividuo);
			          break;
			  case 1: trocar = (pop[j].vg < pop[j+1].vg);
			          break;
			  case 2: trocar = (pop[j].ve < pop[j+1].ve);
			  		  break;
			  case 3: trocar = (pop[j].vf < pop[j+1].vf);
			  		  break;
			  case 4: trocar = (pop[j].sexo < pop[j+1].sexo);
			  		  break;
			  case 5: trocar = (pop[j].geracao < pop[j+1].geracao);
			  		  break;
			}
			if (trocar){
				Individuo aux = pop[j+1];
				pop[j+1] = pop[j];
				pop[j] = aux;
			}
		}
	}
}

void Populacao::imprime(FILE *saida){
	fprintf(saida,"ID \tSX \tVG \tVE \tVF \tidPai \tiidMae \tGeracao \n");
	for (int i=0; i<tam; i++){
		//fprintf(saida,"%d \t%d \t%.3f \t%.3f \t%.3f \n",pop[i].idIndividuo, pop[i].sexo, pop[i].vg, pop[i].ve, pop[i].vf);
		fprintf(saida,"%d \t%d \t%.3f \t%.3f \t%.3f \t%d \t%d \t%.3f \n",pop[i].getId(), pop[i].getSexo(), 
		                                                          pop[i].getValorGenetico(), pop[i].getValorAmbiente(), pop[i].getValorFenotipico(),
																  pop[i].idPai, pop[i].idMae, pop[i].geracao);
	}
	
}

void Populacao::imprime_csv(FILE *saida){
	fprintf(saida,"ID;SX;VG;VE;VF;idPai;iidMae;Geracao; \n");
	for (int i=0; i<tam; i++){
		//fprintf(saida,"%d \t%d \t%.3f \t%.3f \t%.3f \n",pop[i].idIndividuo, pop[i].sexo, pop[i].vg, pop[i].ve, pop[i].vf);
		fprintf(saida,"%d;%d;%.3f;%.3f;%.3f;%d;%d;%.3f; \n",pop[i].getId(), pop[i].getSexo(), 
		                                                          pop[i].getValorGenetico(), pop[i].getValorAmbiente(), pop[i].getValorFenotipico(),
																  pop[i].idPai, pop[i].idMae, pop[i].geracao);
	}
	
}

Populacao Populacao::filtraValor(int campo, int valor){
	bool seleciona;
	int qtde = 0;
	Populacao saida = Populacao(tam);
	for(int i=0; i<tam; i++){
		seleciona= false;
		switch (campo){
			case 1: seleciona = (pop[i].vg == valor);
					break;
			case 2: seleciona = (pop[i].ve == valor);
					break;
			case 3: seleciona = (pop[i].vf == valor);
					break;
			case 4: seleciona = (pop[i].sexo == valor);
					break;
		}
		if (seleciona == true){
			saida.pop[qtde] = pop[i];
			qtde++;
		}
	}
	saida.tam = qtde;
	return saida;
}

Populacao Populacao::filtraValor(int campo, int valor, int qtde){
	bool seleciona;
	int qtdeSaida = 0;
	Populacao saida = Populacao(qtde);
	for(int i=0; i<tam; i++){
		if (qtdeSaida >= qtde)
		   break;
		   
		seleciona= false;
		if (pop[i].idIndividuo != 0){
			
			switch (campo){
				case 1: seleciona = (pop[i].vg == valor);
						break;
				case 2: seleciona = (pop[i].ve == valor);
						break;
				case 3: seleciona = (pop[i].vf == valor);
						break;
				case 4: seleciona = (pop[i].sexo == valor);
						break;
			}
			if (seleciona == true){
				saida.pop[qtdeSaida] = pop[i];
				qtdeSaida++;
			}
			}
	}
	saida.tam = qtdeSaida;
	return saida;
}

int Populacao::geraProgenie(int nMachos, int nFemeas, int nGeracoes, int selecao){
	
	int pos = tamBase;

    std::default_random_engine generator;
	std::normal_distribution<float> environment(mediaE, dpE);
	std::normal_distribution<float> mendeliana(0,dpE/2);

	for (int g=0; g<nGeracoes; g++){
		ordena_desc(selecao); 
		ordena_desc(5); // ordena por geracao
		Populacao popM = filtraValor(4,1,nMachos);
		Populacao popF = filtraValor(4,2,nFemeas);
		popM.ordena_desc(selecao);
		popF.ordena_desc(selecao);
		int aux;
		for (int i=0; i<nFemeas; i++){
			aux = rand() % nMachos;
			Individuo filho = popM.getIndividuo(aux) + popF.getIndividuo(i);
			filho.idIndividuo = pos+1;
			filho.setValorGenetico(filho.vg + mendeliana(generator));
			filho.setValorAmbiente(environment(generator));
			pop[pos++] = filho;
		}
	}
	return 1;
}
