#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int s, e;
vector<vector<int>> adjArray;
vector<int> visited;
stack<int> R;

char IoT_Class[][30] = {
"IoT����", "���ʼ���", "C���α׷���", "������Ű���", "��ȸ��",
"��������ȸ��", "�ڷᱸ��", "�˰���", "�Ӻ����ý��۱���",
"��ǻ�ͳ�Ʈ��ũ", "IoT�÷���", "�ü��", "����ũ�����μ���", "ĸ���������"
};

void DFS_TS(int v) {
	visited[v] = 1;
	//printf("%d ", v);
	for (int i = 0; i < adjArray[v].size(); i++) {
		int x = adjArray[v][i];
		if (visited[x] == 0) {
			DFS_TS(x);
		}
	}
	R.push(v);
}
void topologicalSort2() {
	for (int v = 1; v <= n; v++)
		visited[v] = 0;
	for (int v = 1; v <= n; v++) {
		if (visited[v] == 0) {
			DFS_TS(v);
		}
	}
}
void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
}
int main() {
	cin >> n >> m;
	adjArray.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		AddEdge(s, e);
	}
	topologicalSort2();
	while (R.size()) {
		cout << IoT_Class[R.top() - 1] << " ";
		R.pop();
		if (R.size() != 0 ) cout << " --> ";
	}
}