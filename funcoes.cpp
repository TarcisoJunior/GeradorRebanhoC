#include <math.h>
#include <iostream>
#include <random>
double randNormal(float media, float desvioPadrao){
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(media,desvioPadrao);
	return distribution(generator);
}
