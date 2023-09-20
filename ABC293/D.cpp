#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), C(M);
    vector<char> B(M), D(M);
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--, C[i]--;
    }

    vector<vector<int>> G(2 * N, vector<int>(0));
    rep(i, N) {
        G[2 * i].push_back(2 * i + 1);
        G[2 * i + 1].push_back(2 * i);
    }

    rep(i, M) {
        int a = 2 * A[i], c = 2 * C[i];
        if (B[i] == 'B') a++;
        if (D[i] == 'B') c++;
        G[a].push_back(c);
        G[c].push_back(a);
    }

    int x = 0, y = 0;
    vector<bool> visited(2 * N, false);

    rep(i, 2 * N) {
        if (visited[i]) continue;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        bool is_loop = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (G[v].size() == 1) is_loop = false;
            for (int nv : G[v]) {
                if (visited[nv]) continue;
                visited[nv] = true;
                q.push(nv);
            }
        }

        if (is_loop)
            x++;
        else
            y++;
    }

    cout << x << " " << y << endl;
}