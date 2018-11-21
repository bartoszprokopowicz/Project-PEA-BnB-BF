#include "pch.h"
#include "TimeMeasure.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TimeMeasure::TimeMeasure()
{
	PCFreq = 0.0;
	CounterStart = 0;
}

TimeMeasure::~TimeMeasure()
{
}

double TimeMeasure::getCounter() const
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void TimeMeasure::startCounting()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

void TimeMeasure::saveToFile(vector<double> &czasy, string path)
{
	ofstream file;
	const std::string filename = path;
	file.open(filename, std::ios::out);

	if (file.good())
	{
		for (double i : czasy)
		{
			file << i << endl;
		}
	}

	file.close();
}
