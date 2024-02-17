#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

//  提出 #50322744
/*
MEMO:

e=0.01の時に誤差が少ないとみなして、2個ずつ予測してたけど、e=0.02の時点で無理になってた。
そんなわけない、
よく求まる平均を確認してみると、
res = v(S)(1-2e) +2e
ってなってた。
つまり、本当の値は
v(S) = (res-2e)/(1-2e)
であるはず。

また、多くの場所ですでに採掘済みである場合、それを既知の値として、繰り返し祈り、平均から値を取ることができる。
今回はベイズ推定を必要としない、e==0.01の時のみこの方法を使う。
→まだしてない。

if (empty.size() < 1) empty.push_back({i, j});

これ、2だとWAなった。提出 #50235960（サンプルなら行けたけど。流石に0.01でもあかんらしい。
1にしろ。



ランダム部分を偶奇で網目上に
一点掘って、その周囲の3つが空の時は残りの一個は確実に1個以上。
以上なのまずいな、全てのランダムますに対して探索することになってしまうこれだと。
確実に残りの一個の図形がわかれば、それを使って探索することができる。（期待値的には半分以下で）

最後の油だまりを見つけるために、最後のサイズで占って85％の時に掘るようにしている。
*/
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
    vector<vector<int>> size(M + 1, vector<int>(N * N + 100, 0));
    size[0][0] = 1;
    rep(i, M) {
        rep(j, N * N) {
            if (size[i][j] == 0) continue;
            size[i + 1][j] += size[i][j];
            size[i + 1][j + d[i]] += size[i][j];
        }
    }
    map<int, int> only_size;
    rep(i, M) {
        if (size[M][d[i]] == 1) only_size[d[i]] = i;
    }
    set<int> os;
    for (auto [k, v] : only_size) os.insert(k);

    int mi_H = 1e9, mi_W = 1e9;
    rep(i, M) {
        vector<vector<bool>> has(N, vector<bool>(N, false));
        for (auto [a, b] : ij[i]) {
            has[a][b] = true;
        }
        int max_H = 0, max_W = 0;
        rep(ii, N) {
            int cnt = 0;

            rep(jj, N) {
                if (has[ii][jj]) {
                    cnt++;
                    max_W = max(max_W, cnt);
                } else {
                    cnt = 0;
                }
            }
            rep(jj, N) {
                if (has[jj][ii]) {
                    cnt++;
                    max_H = max(max_H, cnt);
                } else {
                    cnt = 0;
                }
            }
        }
        mi_H = min(mi_H, max_H);
        mi_W = min(mi_W, max_W);
    }

    int mi_H1 = 1e9, mi_W1 = 1e9;
    rep(i, M) {
        vector<vector<bool>> has(N, vector<bool>(N, false));
        for (auto [a, b] : ij[i]) {
            has[a][b] = true;
        }
        int min_H = 1e9, min_W = 1e9;
        rep(ii, N) {
            int cnt = 0;

            rep(jj, N) {
                if (has[ii][jj]) {
                    cnt++;
                    if (jj == N - 1) min_H = min(min_H, cnt);
                } else {
                    if (cnt > 0) min_H = min(min_H, cnt);
                    cnt = 0;
                }
            }
            rep(jj, N) {
                if (has[jj][ii]) {
                    cnt++;
                    if (jj == N - 1) min_W = min(min_W, cnt);
                } else {
                    if (cnt > 0) min_W = min(min_W, cnt);
                    cnt = 0;
                }
            }
        }
        mi_H1 = min(mi_H, min_H);
        mi_W1 = min(mi_W, min_W);
    }

    int max_oil_size = 0;
    rep(s, M) max_oil_size = max(max_oil_size, d[s]);

    int oil_sum = accumulate(all(d), 0);
    vector<pair<int, int>> has_oil(0);
    int oil_count = 0;

    vector<vector<bool>> checked(N, vector<bool>(N, false)), checked1(N, vector<bool>(N, false));
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
        if (os.count(oil_sum - oil_count)) {
            debug("きたあああああ！！！");
            int last_idx = only_size[oil_sum - oil_count];
            while (1) {
                int i = rand() % (N);
                int j = rand() % (N);
                if (checked1[i][j]) continue;
                bool ok = true;
                for (auto [ii, jj] : ij[last_idx]) {
                    int ni = i + ii;
                    int nj = j + jj;
                    if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                        ok = false;
                        break;
                    }
                    if (checked[ni][nj]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) checked1[i][j] = true;

                if (ok) {
                    cout << "q " << has_oil.size() + d[last_idx] << " ";
                    for (auto [i, j] : has_oil) {
                        cout << i << " " << j << " ";
                    }
                    for (auto [ii, jj] : ij[last_idx]) {
                        cout << i + ii << " " << j + jj << " ";
                    }
                    cout << endl;
                    int resp;
                    cin >> resp;
                    int k = has_oil.size() + d[last_idx];
                    int av = (k - oil_sum) * e + oil_sum * (1 - e);
                    double sd = sqrt(k * e * (1 - e));
                    if (resp > av - 1 * sd) {
                        cout << "a " << has_oil.size() + d[last_idx] << " ";
                        for (auto [i, j] : has_oil) {
                            cout << i << " " << j << " ";
                        }
                        for (auto [ii, jj] : ij[last_idx]) {
                            cout << i + ii << " " << j + jj << " ";
                        }
                        cout << endl;

                        int result;
                        cin >> result;

                        if (result == 1) return 0;
                    }
                }
            }
        }
        int i = rand() % (N);
        int j = rand() % (N);
        if (max(mi_H, mi_W) == 1) {
            if (i % 2 == 0 && j % 2 == 0) continue;
            if (i % 2 == 1 && j % 2 == 1) continue;
        } else {
            if (mi_H < mi_W) {
                if (j % mi_W != 0) continue;
                if (i % mi_H1 != 0) continue;
            }
            if (mi_H >= mi_W) {
                if (i % mi_H != 0) continue;
                if (j % mi_W1 != 0) continue;
            }
        }
        if (checked[i][j]) continue;

        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (checked[i][j]) continue;
            cout << "q 1 " << i << " " << j << endl;

            int response;
            cin >> response;

            checked[i][j] = true;

            if (response == 0) continue;

            has_oil.push_back({i, j});
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