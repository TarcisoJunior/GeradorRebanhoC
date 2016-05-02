// Classe individuo - contem os atributos de cada individuo, 
// relativos a valores geneticos, efeito de ambiente, fenotipicos  e coeficiente de geracao
// Autor: Tarciso Pereira Martins Junior - PG Estatística - UFMG
// e-mail: tarciso.junior@gmail.com

class Individuo{
	public:
	int idIndividuo ;
	int idPai, idMae;
	int sexo;
	float vg, ve, vf, geracao;
	
	
	public:
	Individuo(void);
	Individuo(const Individuo &pIndividuo);
	Individuo(int id);
    ~Individuo(void);
    
    Individuo operator + (const Individuo &p);
    Individuo &operator = (const Individuo &pIndividuo);
    
    int getId();
    int getSexo();
    float getValorGenetico();
    float getValorAmbiente();
    float getValorFenotipico();
    int setSexo(int valor);
    int setValorGenetico(float valor);
    int setValorAmbiente(float valor);
    
};


