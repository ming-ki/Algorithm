#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

const int INSTALLED = 2;
const int DEFENDED = 1;
const int NOT_DEFENDED = 0;

int n, m;
int s, e;
vector<vector<int>> adjArray;
vector<int> visited;

int numTuret = 0;

void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}

int aDFS(int v) {
	//visited[v] = 1;
	//printf("%d ", v);
	for (int i = 0; i < adjArray[v].size(); i++) {
		int x = adjArray[v][i];
		if (visited[x] == NOT_DEFENDED) {
			visited[v] = INSTALLED;
			numTuret++;
			return INSTALLED;
		}
		else if (visited[v] != DEFENDED && visited[x] == INSTALLED)
		{
			visited[v] = DEFENDED;
			return DEFENDED;
		}
		else {
			return NOT_DEFENDED;
		}
	}
	return NOT_DEFENDED;

}

void DFS() {
	for (int v = 1; v <= n; v++)
		visited[v] = NOT_DEFENDED;
	for (int v = 1; v <= n; v++) {
		if (aDFS(v) == NOT_DEFENDED) {
			visited[v] = INSTALLED;
			numTuret++;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		numTuret = 0;
		adjArray.clear();
		visited.clear();

		cin >> n >> m;

		adjArray.resize(n + 1);
		visited.resize(n + 1);

		for (int j = 0; j < m; j++) {
			cin >> s >> e;
			AddEdge(s, e);
		}
		DFS();
		printf("%d\n", numTuret);
	}
}