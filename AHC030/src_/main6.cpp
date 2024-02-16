#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 提出 #50195311

signed main() {
    int N, M;
    cin >> N >> M;
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

    int max_oil_size = 0;
    rep(s, M) max_oil_size = max(max_oil_size, d[s]);

    // 1

    int oil_sum = accumulate(all(d), 0);
    vector<pair<int, int>> has_oil(0);
    int oil_count = 0;

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
    rep(i, N) rep(j, N) if (!use.count({i, j})) checked[i][j] = true;

    vector<vector<int>> oil(N, vector<int>(N, 0));

    while (oil_count < oil_sum) {
        int i = rand() % (N);
        int j = rand() % (N);
        if (checked[i][j]) continue;

        if (oil_sum < 10) {
            int ni = i;
            int nj = j;
            if (i < 2) ni = 2;
            if (i > N - 3) ni = N - 3;
            if (j < 2) nj = 2;
            if (j > N - 3) nj = N - 3;

            cout << "q 25 ";
            repp(ii, ni - 2, ni + 3) repp(jj, nj - 2, nj + 3) {
                cout << ii << " " << jj << " ";
            }
            cout << endl;
            int res;
            cin >> res;
            repp(ii, ni - 2, ni + 3) repp(jj, nj - 2, nj + 3) {
                res -= oil[ii][jj];
            }
            if (res < 1 - 2 * e) continue;
        }

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
            oil[i][j] = response;
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