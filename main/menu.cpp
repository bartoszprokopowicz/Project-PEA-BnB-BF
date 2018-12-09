#include "pch.h"
#include "menu.h"

using namespace std;

menu::menu()
{
	defMatrix = vector<vector<int>>(1, vector<int>(1, 0));
	graph.setMatrix(defMatrix);
}

int menu::loop()
{
	int choose = 0;
	string fname = {};
	TimeMeasure time;

	while (true) {
		cout << "Wybierz opcje: " << endl;
		cout << "0 - Wczytaj z pliku dane" << endl;
		cout << "1 - Wygeneruj dane" << endl;
		cout << "2 - Pokaz graf" << endl;
		cout << "--------Algorytmy Doklade---------" << endl;
		cout << "3 - TSP Brute Force" << endl;
		cout << "4 - TSP Branch & Bound" << endl;
		cout << "--------Algorytmy poszukiwania lokalnego---------" << endl;
		cout << "5 - TSP Symulacja wyzarzania" << endl;
		cout << "6 - Wyjdz" << endl;

		cin >> choose;

		switch (choose) {
		case 0:
			cout << "Podaj nazwê pliku: ";
			cin >> fname;
			if (graph.loadFile(fname) == 1) {
				cout << "Wczytano plik!";
				cin.ignore();
				cin.get();
			}
			else {
				cout << "Nie ma takiego pliku!";
				cin.ignore();
				cin.get();
			}
			break;
		case 1:
			cout << "Podaj ile wierzcholkow ma byc w grafie: ";
			int v1;
			cin >> v1;
			cout << endl;
			graph.generateGraph(v1);
			graph.showGraph();
			break;
		case 2:
			graph.showGraph();
			break;
		case 3:
			TSPbruteforce = tspBruteForce(graph.getMatrix());
			cout << "Podaj z ktorego wierzcholka chcesz zaczac: ";
			int v2;
			cin >> v2;
			cout << endl;
			if (v2 > graph.getMatrix().size() - 1 || v2 < 0) {
				cout << "Podaj inny wierzcho³ek!";
				cin.ignore();
				cin.get();
			}
			else {
				time.startCounting();
				result = TSPbruteforce.bruteForce(v2);
				double czas = time.getCounter();
				cout << "Czas wykonania algorytmu: " << czas << "ms" << endl;
				printResult(result);
			} 
			break;
		case 4:
			TSPbranchnbound = tspBranchnBound(graph.getMatrix());
			cout << "Podaj z ktorego wierzcholka chcesz zaczac: ";
			int v3;
			cin >> v3;
			cout << endl;
			if (v3 > graph.getMatrix().size() - 1|| v3 < 0) {
				cout << "Podaj inny wierzcho³ek!";
				cin.ignore();
				cin.get();
			}
			else {
				time.startCounting();
				result = TSPbranchnbound.branchnBound(v3);
				double czas = time.getCounter();
				cout << "Czas wykonania algorytmu: " << czas << "ms" << endl;
				printResult(result);
			}
			break;
		case 5:
			float initTemp;
			float coolingTemp;
			float minTemp;
			int iterations;
			cout << "Podaj wartosci poczatkowe" << endl;
			cout << "Temp poczatkowa: ";
			cin >> initTemp;
			cout << endl;
			cout << "Temp chlodzenia: ";
			cin >> coolingTemp;
			cout << endl;
			cout << "Temp minimalna: ";
			cin >> minTemp;
			cout << endl;
			cout << "ilosc powtorzen: ";
			cin >> iterations;
			cout << endl;
			TSPsimulatedannealing = tspSimulatedAnnealing(graph.getMatrix(), initTemp, coolingTemp, minTemp, iterations);
			result = TSPsimulatedannealing.simulatedAnnealing();
			printResult(result);
			break;
		case 6:
			return 1;
			break;
		default:
			cout << "Wybierz dobra opcje!";
			system("pause");
			break;
		}
		system("cls");
	}
}

void menu::printResult(results &result)
{
	cout << "Najtansza sciezka: ";
	for (int i = 0; i < result.path.size(); i++) {
		cout << result.path[i];
		if (i != result.path.size() - 1)
			cout << "-";
	}
	cout << endl;
	cout << "Koszt sciezki: " << result.cost;
	cin.ignore();
	cin.get();
}


menu::~menu()
{
	graph.~graph();
	TSPbranchnbound.~tspBranchnBound();
	TSPbruteforce.~tspBruteForce();
}

