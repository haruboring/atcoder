#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];

    vector<vector<int>> G(N);
    rep(i, N - 1) {
        G[A[i] - 1].push_back(B[i] - 1);
        G[B[i] - 1].push_back(A[i] - 1);
    }

    vector<int> dist(N, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    int id_max = max_element(all(dist)) - dist.begin();
    dist.assign(N, -1);
    q.push(id_max);
    dist[id_max] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    cout << *max_element(all(dist)) + 1 << endl;
}