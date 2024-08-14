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
    カ: カス種, 本: 本命種


    カカカカカカ
    カ本本本カカ
    カ本本本カカ
    カ本本本カカ
    カカカカカカ
    カカカカカカ

    本命ランキング

    516
    203
    748
    */

    for (int t = 0; t < T; t++) {
        vector<pair<int, int>> V;
        for (int i = 0; i < seed_count; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += X[i][j];
            }
            V.push_back({sum, i});
        }
// Score = 693617
        sort(all(V));
        reverse(all(V));

        vector<pair<int, int>> honmei(9);
        rep(i, 9) honmei[i] = V[i];

        reverse(all(V));  // カス順
        vector<pair<int, int>> kasu(27);
        rep(i, 27) kasu[i] = V[i];

        // カカカカカカ
        rep(i, 6) cout << kasu[i].second << " ";
        cout << endl;
        // カ本本本カカ
        cout << kasu[6].second << " " << honmei[5].second << " " << honmei[1].second << " " << honmei[6].second << " " << kasu[7].second << " " << kasu[8].second << " ";
        cout << endl;
        // カ本本本カカ
        cout << kasu[9].second << " " << honmei[2].second << " " << honmei[0].second << " " << honmei[3].second << " " << kasu[10].second << " " << kasu[11].second << " ";
        cout << endl;
        // カ本本本カカ
        cout << kasu[12].second << " " << honmei[7].second << " " << honmei[4].second << " " << honmei[8].second << " " << kasu[13].second << " " << kasu[14].second << " ";
        cout << endl;
        // カカカカカカ
        rep(i, 6) cout << kasu[i + 15].second << " ";
        cout << endl;
        // カカカカカカ
        rep(i, 6) cout << kasu[i + 21].second << " ";
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