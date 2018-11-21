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
	//Ustawienie kosztu przej�� na maksymaln� warto��
	result.cost = INT_MAX;
	//Dodanie do wektora przej�� miasta pocz�tkowego
	p.push_back(start);
	//Zape�nienie wektora przej�� pozosta�ymi miastami
	for (int i = 0; i < matrix.size(); i++)
		if (i != start) {
			p.push_back(i);
		}
	//Dodanie na koniec przej�cia mi�dzy ostatnim miastem a miastem pocz�tkowym
	p.push_back(start);

	while(true){
		//Algorytm na podstawie :
		//Znajd� najwi�ksze x, takie �e P[x] < P[x+1]
		//(Je�li nie ma takiego x, wychodzimy z p�tli)
		//Znajd� najwi�ksze y, takie �e P[x] < P[y].
		//Zamie� miejscami P[x] z P[y].
		//Obr�� P[x + 1 ..n].
		int temp = INT_MAX;
		
		int largI = -1;
		//i = 1 poniewa� nie chcemy permutacji na p[0]
		//p.size() - 2 poniewa� nie chcemy permutacji na p[n]
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
		//Zamiana miejscami warto�ci z p[x] i p[y]
		int t = p[largI];
		p[largI] = p[largJ];
		p[largJ] = t;
		//Odwr�cenie  p[x + 1 ... n - 1], n - 1, poniewa� nie chcemy permutowa� na ostatniej pozycji
		reverse(p.begin() + largI + 1, p.end() - 1);
		
		//Sprawdzenie czy istnieje droga mi�dzy wierzcho�kami
		for (int i = 0; i < p.size() - 1; i++) {
			//Je�li nie, wychodzimy z p�tli
			if (matrix[p[i]][p[i + 1]] == -1) {
				break;
			}
			else {
				if (temp == INT_MAX)
					temp = 0;
				temp += matrix[p[i]][p[i + 1]];
			}
		}
		//Je�li warto�� temp jest mniejsza ni� dotychczasowy koszt, napisujemy dotychczasowy koszt
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

