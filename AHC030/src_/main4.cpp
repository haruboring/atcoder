#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 提出 #50136756
/*
これはM（油田の数）が1の時があるかを見るために出したクソコード
*/

signed main() {
    int N, M;
    cin >> N >> M;
    if (M == 1) return 0;
    double e;
    cin >> e;
    vector<int> d(M);
    vector<vector<pair<int, int>>> ij(M);
    rep(s, M) {
        cin >> d[s];
        rep(_, d[s]) {
            int i, j;
            cin >> i >> j;
            ij[s].push_back({i, j});
        }
    }

    int oil_sum = accumulate(all(d), 0);
    vector<pair<int, int>> has_oil(0);
    int oil_count = 0;
    int empty_count = 0;

    vector<vector<bool>> checked(N, vector<bool>(N, false));
    // 可能性のない四隅を捨てる
    set<pair<int, int>> use;
    rep(s, M) {
        rep(di, N) {
            rep(dj, N) {
                set<pair<int, int>> tmp;
                bool ok = true;
                for (auto [i, j] : ij[s]) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                        ok = false;
                        break;
                    }
                    tmp.insert({ni, nj});
                }

                if (ok) use.merge(tmp);
            }
        }
    }
    rep(i, N) rep(j, N) if (!use.count({i, j})) {
        checked[i][j] = true;
        empty_count++;
    }

    while (oil_count < oil_sum) {
        int i = rand() % N;
        int j = rand() % N;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (checked[i][j]) continue;
            cout << "q 1 " << i << " " << j << endl;
            int response;
            cin >> response;
            if (response == 0) continue;
            has_oil.push_back({i, j});
            checked[i][j] = true;
            oil_count += response;
            if (oil_count >= oil_sum) break;

            if (i > 0 && !checked[i - 1][j]) q.push({i - 1, j});
            if (i < N - 1 && !checked[i + 1][j]) q.push({i + 1, j});
            if (j > 0 && !checked[i][j - 1]) q.push({i, j - 1});
            if (j < N - 1 && !checked[i][j + 1]) q.push({i, j + 1});
        }
    }

    cout << "a " << has_oil.size() << " ";
    for (auto [i, j] : has_oil) {
        cout << i << " " << j << " ";
    }
    cout << endl;
}
// 8868000000