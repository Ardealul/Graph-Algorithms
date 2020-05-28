#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//afisare noduri izolate intr un graf orientat

#define NR_NODURI 20

vector<int> muchii[NR_NODURI];
vector<int> noduriIzolate;
bool vecin[NR_NODURI];

ifstream fin("graf.in");
ofstream fout("graf.out");

int N, x, y, M = 0;

void citire() {
	fin >> N;
	while (fin >> x >> y) {
		muchii[x].push_back(y);
	}
}

int main() {
	citire();
	cout << "Nodurile izolate sunt: ";
	for (int i = 1; i <= N; i++) {
		if (muchii[i].size() == 0) {
			noduriIzolate.push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < muchii[i].size(); i++) {
			vecin[muchii[i][j]] = true;
		}
	}
	for (int i = 0; i < noduriIzolate.size(); i++) {
		if (vecin[noduriIzolate[i]] == false) {
			cout << noduriIzolate[i] << " ";
		}
	}
	cout << "\n";
	system("pause");
	return 0;
}