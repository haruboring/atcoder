#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, T;
    cin >> N >> M >> T;  // N=6, M=15, T=10

    // N^2 = 36
    // 2N(N-1)=60

    int seed_count = 2 * N * (N - 1);
    vector<vector<int>> X(seed_count, vector<int>(M, 0));

    for (int i = 0; i < seed_count; i++) {
        for (int j = 0; j < M; j++) {
            cin >> X[i][j];
        }
    }

    for (int t = 0; t < T; t++) {
        vector<pair<int, int>> V;
        for (int i = 0; i < seed_count; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += X[i][j];
            }
            V.push_back({sum, i});
        }

        sort(all(V));
        reverse(all(V));

        vector<pair<int, int>> honmei(N * 3);
        rep(i, 3) {  // N=6にのみ対応
            honmei[N * i + 1] = V[N * i];
            honmei[N * i + 0] = V[N * i + 1];  // 本命の中でも本命
            honmei[N * i + 2] = V[N * i + 2];
            honmei[N * i + 3] = V[N * i + 3];
            honmei[N * i + 4] = V[N * i + 4];
            honmei[N * i + 5] = V[N * i + 5];
        }

        reverse(all(V));  // カス順

        rep(i, N) cout << V[i + 2 * N].second << " ";  // カス種
        cout << endl;
        rep(i, N) cout << V[i + 0 * N].second << " ";  // カス種
        cout << endl;
        rep(i, N) cout << honmei[i + 1 * N].second << " ";
        cout << endl;
        rep(i, N) cout << honmei[i + 0 * N].second << " ";  // 本命ライン
        cout << endl;
        rep(i, N) cout << honmei[i + 2 * N].second << " ";
        cout << endl;
        rep(i, N) cout << V[i + 1 * N].second << " ";  // カス種
        cout << endl;

        cout.flush();

        for (int i = 0; i < seed_count; i++) {
            for (int j = 0; j < M; j++) {
                cin >> X[i][j];
            }
        }
    }

    return 0;
}