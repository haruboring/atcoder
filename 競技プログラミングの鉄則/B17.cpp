#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> h(N + 1), cost(N + 1);
    rep(i, N) {
        cin >> h[i + 1];
    }
    cost[2] = abs(h[2] - h[1]);
    repp(i, 3, N + 1) {
        cost[i] = min(cost[i - 1] + abs(h[i] - h[i - 1]), cost[i - 2] + abs(h[i] - h[i - 2]));
    }
    int pos = N;
    vector<int> path(0);
    while (1) {
        path.push_back(pos);
        if (pos <= 1) {
            break;
        }
        if (cost[pos] - cost[pos - 1] == abs(h[pos] - h[pos - 1])) {
            pos--;
        } else {
            pos -= 2;
        }
    }
    sort(all(path));
    cout << path.size() << endl;
    rep(i, path.size()) {
        cout << path[i] << " ";
    }
    cout << endl;
}