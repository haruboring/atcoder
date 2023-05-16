#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> G(100000 + 100, vector<int>(0));
int K = 0;
map<pair<int, int>, int> colors;

void dfs(int top, int ex_top = -1) {
    int i = 1;
    for (auto next_top : G[top]) {
        if (next_top == ex_top) {
            continue;
        }
        if (i == colors[make_pair(top, ex_top)]) {
            i++;
        }
        colors[make_pair(top, next_top)] = i;
        colors[make_pair(next_top, top)] = i;
        dfs(next_top, top);
        K = max(K, i);
        i++;
    }
}

int main() {
    int N;
    cin >> N;

    map<pair<int, int>, int> C;
    vector<int> a(N - 1), b(N - 1);

    rep(i, N - 1) {
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        colors[make_pair(a[i], b[i])] = -1;
        colors[make_pair(b[i], a[i])] = -1;
    }

    dfs(1);

    cout << K << endl;

    rep(i, N - 1) {
        cout << colors[make_pair(a[i], b[i])] << endl;
    }
}