#include "pch.h"
#include "tspSimulatedAnnealing.h"


tspSimulatedAnnealing::tspSimulatedAnnealing(vector<vector<int>> matrix, float initTemp, float coolingTemp, float minimalTemp, int iterations)
	: matrix(matrix), initTemp(initTemp), coolingTemp(coolingTemp),
	minimalTemp(minimalTemp), iterations(iterations), nowTemp(initTemp)
{
}

tspSimulatedAnnealing::tspSimulatedAnnealing()
{
}

results tspSimulatedAnnealing::simulatedAnnealing()
{
	srand(time(NULL));
	//tworzenie losowej drogi i wyznaczanie trasy
	for (int i = 1; i < matrix.size(); i++) {
		nowResult.path.push_back(i);
	}
	nowResult.path.push_back(0);
	bestResult.path = nowResult.path;
	bestResult.cost = calculateCost();
	
	uniform_real_distribution<double> distribution(0.0, 1.0);
	default_random_engine generator;

	while (nowTemp > minimalTemp)
	{
		for (int i = 0; i < iterations; i++)
		{
			randSwap();
			nowResult.cost = calculateCost();

			if (nowResult.cost < bestResult.cost)
			{
				bestResult = nowResult;
			}
			else if (probability() > distribution(generator))
			{
				bestResult = nowResult;
			}
		}
		nowTemp *= coolingTemp;
	}
	return bestResult;
}

double tspSimulatedAnnealing::probability()
{
	double power = -((nowResult.cost - bestResult.cost) / nowTemp);
	return pow(M_E, power);
}

int tspSimulatedAnnealing::calculateCost()
{
	int temp = 0;
	//obliczenie kosztu przejœcia
	for (int i = 0; i < nowResult.path.size() - 1; i++) 
		temp += matrix[nowResult.path[i]][nowResult.path[i + 1]];
		
	return temp;
}

void tspSimulatedAnnealing::randSwap()
{
	int cityCount = bestResult.path.size();
	int a = rand() % (cityCount - 2) + 1;
	int b = rand() % (cityCount - 2) + 1;
	while (a == b)
		b = rand() % (cityCount - 2) + 1;
	//swap
	nowResult = bestResult;
	int tmp = nowResult.path[a];
	nowResult.path[a] = nowResult.path[b];
	nowResult.path[b] = tmp;
}

void tspSimulatedAnnealing::randInsert()
{
}

void tspSimulatedAnnealing::randInverse()
{
}

tspSimulatedAnnealing::~tspSimulatedAnnealing()
{
}
