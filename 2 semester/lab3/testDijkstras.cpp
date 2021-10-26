#include <iostream>
#include <ctime>
#include <queue>
#include <ctime>
#include "tests.h"

using namespace std;

int DijkstraQueue(int v1, int v2, const int size, int** array) {
	queue <int> q;
	int* dist = new int[size];
	
	q.push(v1);
	
	for (int i = 0; i < size; i++) {
		dist[i] = 100000;
	}

	dist[v1] = 0;
	while (!q.empty()){
		int v = q.front();
		q.pop();

		for (int i = 0; i < size; i++) {
			if (array[v][i] != -1 && dist[i] > dist[v] + array[v][i]) {
				q.push(i);
				dist[i] = dist[v] + array[v][i];
			}
		}
	}
	
	if (dist[v2] == 100000) return -1;

	return dist[v2];
}

int DijkstraPriorityQueue(int v1, int v2, const int size, int** array) {
	priority_queue <int> q;
	int* dist = new int[size];

	q.push(v1);

	for (int i = 0; i < size; i++) {
		dist[i] = 100000;
	}

	dist[v1] = 0;
	while (!q.empty()) {
		int v = q.top();
		q.pop();

		for (int i = 0; i < size; i++) {
			if (array[v][i] != -1 && dist[i] > dist[v] + array[v][i]) {
				q.push(i);
				dist[i] = dist[v] + array[v][i];
			}
		}
	}

	if (dist[v2] == 100000) return -1;

	return dist[v2];
}


void DijkstrasAlgorithm() {
	srand(time(NULL));

	int amtVer = 20000;
	int** mtrx = new int*[amtVer];
	for (int i = 0; i < amtVer; i++) {
		mtrx[i] = new int[amtVer];
		for (int j = 0; j < amtVer; j++) {
			mtrx[i][j] = -1;
		}
	}

	int amtWays = 40000;
	while (amtWays) {
		int x = rand() % amtVer;
		int y = rand() % amtVer;
		if (x != y) {
			int weight = rand() % 10 + 1;
			mtrx[x][y] = weight;
			mtrx[y][x] = weight;
			amtWays--;
		}
	}

	int v1 = rand() % amtVer;	// початкова вершина
	int v2 = rand() % amtVer;	// кінцева вершина


	// Алгоритм дейкстри зі звичайною чергою
	clock_t timeStart = clock();
	DijkstraQueue(v1, v2, amtVer, mtrx);
	clock_t timeEnd = clock();
	float timeQueue = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;


	// Алгоритм дейкстри з пріоритетною чергою 
	timeStart = clock();
	DijkstraPriorityQueue(v1, v2, amtVer, mtrx);
	timeEnd = clock();
	float timePriorityQueue = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;

	cout << "Dijkstra queue time:" << endl;
	cout << "Time: " << timeQueue << endl;
	cout << "Dijkstra priority queue time:" << endl;
	cout << "Time: " << timePriorityQueue << endl;

}