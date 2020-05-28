#include <fstream>
#include <iostream>
#include <queue>
#define INFINIT 10000
using namespace std;

int a[15][15], dist[101], n, i, j, start, vizitat[100],noduri[20],minim,min_index;
queue <int> q;

ifstream fin("dijkstra.in");

void citire()
{
	fin >> n;
	int x, y, z;
	while (!fin.eof())
	{
		fin >> x >> y >> z;
		a[x][y] = z;
	}
	cout << "Nodul de start: ";
	cin >> start;
}

void initializare()
{
	for (int i = 1; i <= n; i++) {
		if (start != i) {
			dist[i] = INFINIT;
		}
	}
	dist[start]=0;
	for (i = 1; i <= n; i++) {
		if (a[start][i] != 0)
			dist[i] = a[start][i];
	}
}

void dijkstra(int nod)
{
	q.push(nod);
	vizitat[nod] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (i = 1; i <= n; i++)
		{
			if (a[x][i] != 0)
			{
				if (dist[i] > dist[x] + a[x][i])
				{
					dist[i] = dist[x] + a[x][i];
				}
				if (vizitat[i] == 0)
				{
					vizitat[i] = 1;
					q.push(i);
				}
			}
		}
	}
}

int smaller() {
	minim = INFINIT;
	min_index = -1;
	for (int i = 1; i <= n; i++) {
		if (vizitat[i] == 0 && dist[i]<=minim) {
			minim = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void dickstra() {
	//int x = start;
	int y = smaller();
	while (y != -1) {
		vizitat[y] = 1;
		for (int i = 1; i <= n; i++) {
			if (a[y][i] > 0) {
				if (dist[i] > dist[y] + a[y][i]) {
					dist[i] = dist[y] + a[y][i];
				}
			}
		}
		y = smaller();
	}
}

int main()
{
	citire();
	initializare();
	dickstra();
	cout << "Distanta de la nodul de start " << start << " la toate celelalte noduri:" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << start << "->" << i << " : " << dist[i] << " " << endl;
	}
	return 0;
}

