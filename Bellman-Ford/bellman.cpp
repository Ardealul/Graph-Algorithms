#include <iostream>
#include <fstream>
#define inf 100000

using namespace std;
ifstream f("bellman.in");

int i, j, n, edges=0, start, dist[101], x, y, z;


struct edge {
	int x, y, z;
}v[101];

void citire()
{
	int b, c, d;
	f >> n;
	edges = 0;
	while (!f.eof())
	{
		f >> b >> c >> d;
		edges++;
		v[edges].x = b;
		v[edges].y = c;
		v[edges].z = d;
	}
	cout << "Nod start: ";
	cin >> start;
}

void initializare()
{
	for (i = 1; i <= n; i++)
		dist[i] = inf;
	dist[start] = 0;
	for (i = 1; i <= edges; i++)
		if (v[i].x == start)
			if (dist[v[i].y] > v[i].z)
				dist[v[i].y] = v[i].z;
}

//complexitate 0(E*(V-1))=0(n*m)
void bellman_ford()
{
	for (i = 1; i < n ; i++)
		for (j = 1; j <= edges; j++)
			if (dist[v[j].y] > dist[v[j].x] + v[j].z)
				dist[v[j].y] = dist[v[j].x] + v[j].z;
}

int main()
{

	citire();
	initializare();
	bellman_ford();
	cout << "Cel mai scurt nod din " << start << " la toate nodurile este: " << endl;
	for (i = 1; i <= n; i++)
		cout << start << "->" << i <<" : "<< dist[i] << " " << endl;
	return 0;
}
/*
4
1 2 4
1 4 5
4 3 3
3 2 -10
*/