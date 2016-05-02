Individuo::Individuo(void){
	idIndividuo = 0;
	idPai = 0;
	idMae = 0;
	sexo = 0;
	vg = 0;
	ve = 0;
	vf = 0;
	geracao = 0;
}

Individuo::Individuo(const Individuo &pIndividuo){
	idIndividuo = pIndividuo.idIndividuo;
	idPai = pIndividuo.idPai;
	idMae = pIndividuo.idMae;
	sexo = pIndividuo.sexo;
	vg = pIndividuo.vg;
	ve = pIndividuo.ve;
	vf = pIndividuo.vf;
	geracao = pIndividuo.geracao;
}

Individuo::Individuo(int id){
	idIndividuo = id;
	idPai = 0;
	idMae = 0;
	sexo = 0;
	vg = 1;
	ve = 0;
	vf = 0;
	geracao = 0;
}

Individuo::~Individuo(void){
	//fprintf(stdout,"Individuo -> destrutor");
}

int Individuo::getId(){
	return idIndividuo;
}

int Individuo::getSexo(){
	return sexo;
}

float Individuo::getValorGenetico(){
	return vg;
}

float Individuo::getValorAmbiente(){
	return ve;
}

float Individuo::getValorFenotipico(){
	return vf;
}

int Individuo::setSexo(int valor){
	sexo = valor;
}

int Individuo::setValorGenetico(float valor){
	vg = valor;
	vf = vg + ve;
	return 0;
}

int Individuo::setValorAmbiente(float valor){
	ve = valor;
	vf = vg + ve;
	return 0;
}


Individuo Individuo::operator + (const Individuo &p){
	Individuo Aux;
	Aux.idIndividuo = 0;
	Aux.idPai = idIndividuo;
	Aux.idMae = p.idIndividuo;
	Aux.sexo = rand() % 2 +1;
	Aux.vg =((vg + p.vg) / 2 );
	Aux.ve =(ve + p.ve) / 2;
	Aux.vf = Aux.vg + Aux.ve;
	Aux.geracao = 1+ (geracao + p.geracao) / 2;
	
	return Aux;
}

Individuo &Individuo::operator = (const Individuo &pIndividuo) {
	idIndividuo = pIndividuo.idIndividuo;
	idPai = pIndividuo.idPai;
	idMae = pIndividuo.idMae;
	sexo = pIndividuo.sexo;
	vg = pIndividuo.vg;
	ve = pIndividuo.ve;
	vf = pIndividuo.vf;
	geracao = pIndividuo.geracao;
}
