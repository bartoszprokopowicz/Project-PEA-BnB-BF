#include "pch.h"
#include "tspBranchnBound.h"

tspBranchnBound::tspBranchnBound()
{
}

tspBranchnBound::~tspBranchnBound()
{
}

tspBranchnBound::tspBranchnBound(vector<vector<int>> matrix) : matrix(matrix)
{}

vector<int> tspBranchnBound::rowReduction(vector<vector<int>> &matrix)
{
	vector<int> minRow(matrix.size(), INT_MAX);
	//sprawdzenie wierszy
	for (unsigned i = 0; i < minRow.size(); i++) {
		for (unsigned j = 0; j < minRow.size(); j++) {
			if (matrix[j][i] != -1 && matrix[j][i] < minRow[j])
				minRow[j] = matrix[j][i];
		}
	}

	//odjêcie wartoœci w wierszach
	for (unsigned i = 0; i < minRow.size(); i++) {
		for (unsigned j = 0; j < minRow.size(); j++) {
			if (matrix[j][i] != -1)
				matrix[j][i] -= minRow[j];
		}
	}
	//Zabezpieczenie przed zredukowanymi wierszami
	replace(minRow.begin(), minRow.end(), INT_MAX, 0);

	return minRow;
}

vector<int> tspBranchnBound::columnReduction(vector<vector<int>> &matrix)
{
	vector<int> minCol(matrix.size(), INT_MAX);
	//sprawdzenie kolumn
	for (unsigned j = 0; j < minCol.size(); j++) {
		for (unsigned i = 0; i < minCol.size(); i++) {
			if (matrix[i][j] != -1 && matrix[i][j] < minCol[j])
				minCol[j] = matrix[i][j];
		}
	}

	//odjêcie wartoœci w kolumnach
	for (unsigned i = 0; i < minCol.size(); i++) {
		for (unsigned j = 0; j < minCol.size(); j++) {
			if (matrix[j][i] != -1)
				matrix[j][i] -= minCol[i];
		}
	}
	//Zabezpieczenie przed zredukowanymi kolumnami
	replace(minCol.begin(), minCol.end(), INT_MAX, 0);

	return minCol;
}

int tspBranchnBound::calculateCost(vector<vector<int>> &matrix)
{
	vector<int> minRow = rowReduction(matrix);
	vector<int> minCol = columnReduction(matrix);
	//zwraca zsumowan¹ wartoœæ z redukcji macierzy
	return accumulate(minRow.begin(), minRow.end(), 0) +
		   accumulate(minCol.begin(), minCol.end(), 0);
}

results tspBranchnBound::branchnBound(const int start)
{
	//Funktor sortuj¹cy dane pod wzglêdem wartoœci przejœæ malej¹co
	auto compare = [](const treeNode &nl, const treeNode &nr) {if (nl.sum < nr.sum) return false;
															   if (nl.sum > nr.sum) return true;
															   return true; };
	//Kolejka priorytetowa dla liœci w drzewie
	priority_queue<treeNode, std::vector<treeNode>, decltype(compare)> pq(compare);
	//Œcie¿ka przejœæ w drzewie
	vector<int> path;
	//Wstawienie miasta pocz¹tkowego
	path.push_back(start);
	//Ustawienie sumy zredukowanych wierszy i kolumny
	int sum = calculateCost(matrix);
	//Tworzymy korzeñ miasta pocz¹tkowego
	treeNode root = treeNode::rootNode(matrix, path, start);
	//Ustawienie wartoœci zredukowanych wierszy i kolumny
	root.sum = sum;
	//Dodajemy pierwsze miasto do kolejki priorytetowej
	pq.push(root);

	//W³aœciwy algorytm
	//1.Znajduje liœæ z najmniejszym kosztem
	//2.Dodaje jego dzieci do kolejki a nastêpnie usuwa go z pamiêci
	while (!pq.empty())
	{
		//Wziêcie z kolejki priorytetowej miasta z najmniejszym kosztem
		treeNode min = pq.top();
		//Znalezione miasto usuwamy z kolejki priorytetowej
		pq.pop();
		//Ustalamy które miasto aktualnie sprawdzamy
		int i = min.city;
		//Gdy wszystkie poziomy zosta³y sprawdzone, zwracamy œcie¿kê oraz koszt tej œcie¿ki
		if (min.level == matrix.size() - 1)
		{
			results result;
			//Ustawienie œcie¿ki do miasta pocz¹tkowego
			min.path.push_back(start);
			//Ustawienie wyników znajduj¹cych siê w najm³odszym i najoptymalniejszym z liœci
			result.path = min.path;

			result.cost = min.sum;

			return result;
		}

		for (unsigned j = 0; j < matrix.size(); j++)
		{	
			//Dla ka¿dego przejœcia z liœcia min sprawdzamy czy istnieje przejœcie
			if (min.reduced_matrix[i][j] != -1)
			{
				//Tworzymy nowy obiekt który jest dzieckiem poprzedniego liœcia
				treeNode nextNode = treeNode::newNode(min.reduced_matrix, min.path, min.level + 1, i, j);
				//Obliczamy koszta przejœcia z rodzica do dziecka
				nextNode.sum = min.sum + calculateCost(nextNode.reduced_matrix) + min.reduced_matrix[i][j];
				//Dodajemy do kolejki priorytetowej dziecko poprzedniego liœcia
				pq.push(nextNode);
				//Usuwamy z pamiêci nowy obiekt
				nextNode.~treeNode();
				
			}
		}
		//Usuwamy z pamiêci stary obiekt
		min.~treeNode();
	}
}