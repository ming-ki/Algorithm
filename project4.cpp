#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
vector<int> result;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m, sum = 0;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            p.push_back(x);
        }

        while (p.size() > 1) {
            int x1, x2;

            sort(p.begin(), p.end(), greater<int>());

            x1 = p.back();
            p.pop_back();

            x2 = p.back();
            p.pop_back();

            p.push_back(x1 + x2);
            sum += x1 + x2;
        }
        result.push_back(sum);
        p.clear();
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}