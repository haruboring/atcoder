#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> e(200010, vector<int>(0));
vector<bool> flag(200010);
deque<int> deq;
bool stop;

void dfs(int position, int goal) {
    if (!stop) {
        deq.push_back(position);
    }
    if (position == goal) {
        stop = true;
    }
    flag[position] = true;
    int sz = e[position].size();
    for (int i = 0; i < sz; i++) {
        if (!flag[e[position][i]]) {
            dfs(e[position][i], goal);
        }
    }
    if (!stop) deq.pop_back();
    return;
}

int main(void) {
    int N, X, Y;
    cin >> N >> X >> Y;
    int U, V;
    rep(i, N - 1) {
        cin >> U >> V;
        e[U].push_back(V);
        e[V].push_back(U);
    }
    repp(i, 1, N + 1) {
        flag[i] = false;
    }
    stop = false;
    dfs(X, Y);

    while (!deq.empty()) {
        cout << deq.front();
        deq.pop_front();
        if (deq.empty())
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}