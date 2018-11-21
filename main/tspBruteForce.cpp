#include "pch.h"
#include "tspBruteForce.h"


tspBruteForce::tspBruteForce(vector<vector<int>> matrix) : matrix(matrix)
{
}

tspBruteForce::tspBruteForce()
{
}

results tspBruteForce::bruteForce(int start)
{
	vector<int> p;
	results result;
	//Ustawienie kosztu przejœæ na maksymaln¹ wartoœæ
	result.cost = INT_MAX;
	//Dodanie do wektora przejœæ miasta pocz¹tkowego
	p.push_back(start);
	//Zape³nienie wektora przejœæ pozosta³ymi miastami
	for (int i = 0; i < matrix.size(); i++)
		if (i != start) {
			p.push_back(i);
		}
	//Dodanie na koniec przejœcia miêdzy ostatnim miastem a miastem pocz¹tkowym
	p.push_back(start);

	while(true){
		//Algorytm na podstawie :
		//ZnajdŸ najwiêksze x, takie ¿e P[x] < P[x+1]
		//(Jeœli nie ma takiego x, wychodzimy z pêtli)
		//ZnajdŸ najwiêksze y, takie ¿e P[x] < P[y].
		//Zamieñ miejscami P[x] z P[y].
		//Obróæ P[x + 1 ..n].
		int temp = INT_MAX;
		
		int largI = -1;
		//i = 1 poniewa¿ nie chcemy permutacji na p[0]
		//p.size() - 2 poniewa¿ nie chcemy permutacji na p[n]
		for (int i = 1; i < p.size() - 2; i++) {
			if (p[i] < p[i + 1]) {
				largI = i;
			}
		}

		if (largI == -1) {
			break;
		}

		int largJ = -1;
		for (int j = 1; j < p.size() - 1; j++) {
			if (p[largI] < p[j]) {
				largJ = j;
			}
		}
		//Zamiana miejscami wartoœci z p[x] i p[y]
		int t = p[largI];
		p[largI] = p[largJ];
		p[largJ] = t;
		//Odwrócenie  p[x + 1 ... n - 1], n - 1, poniewa¿ nie chcemy permutowaæ na ostatniej pozycji
		reverse(p.begin() + largI + 1, p.end() - 1);
		
		//Sprawdzenie czy istnieje droga miêdzy wierzcho³kami
		for (int i = 0; i < p.size() - 1; i++) {
			//Jeœli nie, wychodzimy z pêtli
			if (matrix[p[i]][p[i + 1]] == -1) {
				break;
			}
			else {
				if (temp == INT_MAX)
					temp = 0;
				temp += matrix[p[i]][p[i + 1]];
			}
		}
		//Jeœli wartoœæ temp jest mniejsza ni¿ dotychczasowy koszt, napisujemy dotychczasowy koszt
		if (temp < result.cost) {
			result.cost = temp;
			result.path = p;
		}	
	}

	return result;
}




tspBruteForce::~tspBruteForce()
{
}

