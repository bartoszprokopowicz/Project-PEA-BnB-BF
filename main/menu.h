#pragma once
#include <iostream>
#include <string>
#include "results.h"
#include "Graph.h"
#include "tspBruteForce.h"
#include "tspBranchnBound.h"
#include "tspSimulatedAnnealing.h"
#include "TimeMeasure.h"

class menu
{
private:
	vector<vector<int>> defMatrix;
	graph graph;
	tspBruteForce TSPbruteforce;
	tspBranchnBound TSPbranchnbound;
	tspSimulatedAnnealing TSPsimulatedannealing;
	results result;

public:
	menu();
	int loop();
	void printResult(results &result);
	~menu();
};
