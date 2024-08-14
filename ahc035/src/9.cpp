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

    /*
    35 34 33 32 31 30
    29 10 9  12 15 28
    27 5  1  6  13 26
    25 2  0  3  11 24
    23 7  4  8  14 22
    21 20 19 18 17 16
    */

    // 総和順で植える, カス度合いでのスコアアップは考慮しない。
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

        // 35 34 33 32 31 30
        cout << V[35].second << " " << V[34].second << " " << V[33].second << " " << V[32].second << " " << V[31].second << " " << V[30].second << endl;
        cout << endl;
        // 29 10 9  12 15 28
        cout << V[29].second << " " << V[10].second << " " << V[9].second << " " << V[12].second << " " << V[15].second << " " << V[28].second << endl;
        cout << endl;
        // 27 5  1  6  13 26
        cout << V[27].second << " " << V[5].second << " " << V[1].second << " " << V[6].second << " " << V[13].second << " " << V[26].second << endl;
        cout << endl;
        // 25 2  0  3  11 24
        cout << V[25].second << " " << V[2].second << " " << V[0].second << " " << V[3].second << " " << V[11].second << " " << V[24].second << endl;
        cout << endl;
        // 23 7  4  8  14 22
        cout << V[23].second << " " << V[7].second << " " << V[4].second << " " << V[8].second << " " << V[14].second << " " << V[22].second << endl;
        cout << endl;
        // 21 20 19 18 17 16
        cout << V[21].second << " " << V[20].second << " " << V[19].second << " " << V[18].second << " " << V[17].second << " " << V[16].second << endl;
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