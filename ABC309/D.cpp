#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    vector<int> a(M), b(M);
    rep(i, M) cin >> a[i] >> b[i];

    vector<vector<int>> G1(N1), G2(N1 + N2);
    rep(i, M) {
        a[i]--;
        b[i]--;
        if (a[i] < N1) {
            G1[a[i]].push_back(b[i]);
            G1[b[i]].push_back(a[i]);
        } else {
            G2[a[i]].push_back(b[i]);
            G2[b[i]].push_back(a[i]);
        }
    }

    queue<int> q;
    vector<int> dist(N1, -1);
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G1[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    ll G1_dis = *max_element(all(dist));

    dist.assign(N1 + N2, -1);
    q.push(N1 + N2 - 1);
    dist[N1 + N2 - 1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G2[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    ll G2_dis = *max_element(all(dist));

    cout << G1_dis + G2_dis + 1 << endl;
}