#pragma once
#include <vector>
#include <math.h>
#include <time.h>
#include <random>
#include "results.h"

constexpr auto M_E = 2.71828182845904523536;

using namespace std;

class tspSimulatedAnnealing
{
private:
	//Macierz przejœæ do miast
	vector<vector<int>> matrix;
	//Zmienne potrzebne do wy¿arzania
	float initTemp;
	float coolingTemp;
	float minimalTemp;
	float nowTemp;
	int iterations;
	//Wyniki
	results oldResult;
	results nowResult;
	results bestResult;

public:
	tspSimulatedAnnealing(vector<vector<int>> matrix, float initTemp, float coolingTemp, float minimalTemp, int iterations);
	tspSimulatedAnnealing();

	results simulatedAnnealing();
	double probability();
	int calculateCost();
	void randSwap();
	void randInsert();
	void randInverse();
	

	~tspSimulatedAnnealing();
};

