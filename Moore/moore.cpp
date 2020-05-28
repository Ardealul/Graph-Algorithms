#include <iostream>
#include <fstream>
#define INF -1

using namespace std;

typedef struct {
	int vecini[20], nr;
}ListaAdiacenta;


void moore(ListaAdiacenta* G, int u, int nrNoduri) {
	int L[20], Q[20], P[20] = { 0 }, lung = 0;
	L[u] = 0;
	for (int i = 1; i <= nrNoduri; i++) {
		if (u != i) {
			L[i] = INF;
		}
	}
	Q[lung++] = u;
	while (lung > 0) {
		int x = Q[--lung];
		for (int i = 1; i <= G[x].nr; i++) {
			int y = G[x].vecini[i];
			if (L[y] == INF) {
				P[y] = x;
				L[y] = L[x] + 1;
				Q[lung++] = y;
			}
		}
	}
	//tiparire parinti
	for (int i = 1; i <= nrNoduri; i++) {
		if (u != i) {
			cout << "Parintele lui " << i << " este " << P[i] << endl;
		}
		else
			cout << "Parintele lui " << i << " este 0" << endl;
	}
	//tiparire drum
	for (int i = 1; i <= nrNoduri; i++) {
		if (i != u && G[i].nr>0 && i!=9) {
			int k, u1;
			k = L[i];
			u = i;
			cout << "Drumul de la nodul " << i << " la sursa 1 este : " << endl;
			cout << u << ",";
			while (k != 0){
				u = P[u];
				k--;
				cout << u << ",";
			}
			cout << endl;
		}
	}
}

void matriceTranz(ListaAdiacenta* G, int nrNoduri) {
	for (int i = 1; i <= nrNoduri; i++) {
		cout << "Din nodul " << i << " se poate ajunge in: ";
		for (int j = 1; j <= G[i].nr; j++) {
			cout << G[i].vecini[j] << " ";
		}
		cout << endl;
	}
}

int main() {

	ifstream f("moore.in");
	ListaAdiacenta G[20] = { 0 };
	int i, j, u, nrNoduri;
	f >> nrNoduri;
	while (!f.eof()) {
		f >> i >> j;
		G[i].vecini[++G[i].nr] = j; //completare vecini nod i
		//G[j].vecini[++G[j].nr]=i; //asta pt graf neorientat
	}
	cout << "Nodul sursa: "; cin >> u;

	moore(G, u, nrNoduri);
	cout << "Matriacea tranzitiva: " << endl;
	matriceTranz(G, nrNoduri);

	system("pause");
	return 0;
}