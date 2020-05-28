#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int n, a, b, i, k, j, muchii = 0;
	ifstream f("fisier.txt");
	f >> n;
	cout << n << endl;
	int mat[50][50];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			mat[i][j] = 0;

	while (f >> a >> b) {
		cout << "Muchia " << a << "-" << b << endl;
		mat[a - 1][b - 1] = 1;
		mat[b - 1][a - 1] = 1;
		muchii++;
	}

	f.close();
	cout << endl << "Matricea de adicenta: ";
	for (i = 0; i < n; i++) {
		cout << endl;
		for (j = 0; j < n; j++)
			cout << mat[i][j] << " ";
	}
	int mat_i[50][50];

	for (i = 0; i < n; i++)
		for (j = 0; j < muchii; j++)
			mat_i[i][j] = 0;

	k = 0;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++) {
			if (mat[i][j] == 1) {

				mat_i[i][k] = 1;
				mat_i[j][k] = 1;
				k++;
			}
		}

	cout << endl << "Matricea de incidenta: ";
	for (i = 0; i < n; i++) {
		cout << endl;
		for (j = 0; j < k; j++)
			cout << mat_i[i][j] << " ";
	}
	int nr, mat_aj[50][50];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			mat_aj[i][j] = 0;

	for (j = 0; j < muchii; j++)
	{
		a = 0;
		b = 0;
		nr = 0;
		for (i = 0; i < n; i++) {
			if (mat_i[i][j] == 1) {
				nr++;
				a = b;
				b = i;
			}
			if (nr == 2) {
				mat_aj[a][b] = mat_aj[b][a] = 1;
				break;
			}
		}
	}
	cout << endl << "Matricea de adicenta: ";
	for (i = 0; i < n; i++) {
		cout << endl;
		for (j = 0; j < n; j++)
			cout << mat_aj[i][j] << " ";
	}
	cout << endl << "Lista de adiacenta: ";
	for (i = 0; i < n; i++) {
		cout << endl;
		cout << i + 1 << " : ";
		for (j = 0; j < n; j++)
			if (mat[i][j] == 1)
				cout << j + 1 << " ";
	}

	system("pause");
	return 0;
}