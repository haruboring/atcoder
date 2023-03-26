#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<bool> is_visited(200000 + 1, false);
vector<set<int>> G(200000 + 1), copyG;
int circle_cnt = 0;

void solve(int top, int start) {
    is_visited[top] = true;
    for (auto next : G[top]) {
        if (is_visited[next] = false) {
            
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int A, B;
        cin >> A >> B;
        G[A].insert(B);
        G[B].insert(A);
    }
}