#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

//
/*
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

2*N*Nまでなのえぐ、一ヶ所あたり二回？？無理では？
*/

// 正規分布の確率密度関数
double normal_pdf(double x, double mu, double sigma) {
    return (1.0 / (sigma * sqrt(2 * M_PI))) * exp(-0.5 * pow((x - mu) / sigma, 2));
}

// 尤度の計算
double likelihood(int vS, const std::vector<double>& data, double epsilon, double k) {
    double mu = (k - vS) * epsilon + vS * (1 - epsilon);
    double sigma_squared = k * epsilon * (1 - epsilon);
    double sigma = sqrt(sigma_squared);
    double result = 1.0;

    for (double x : data) {
        result *= normal_pdf(x, mu, sigma);
    }

    return result;
}

signed main() {
    int N, M;
    cin >> N >> M;
    double e;
    cin >> e;
    debug(e);
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
    rep(i, N) rep(j, N) {
        if (!use.count({i, j})) {
            checked[i][j] = true;
        }
    }

    debug(oil_sum);

    vector<vector<int>> oil(N, vector<int>(N, 0));

    bool check = false;

    while (oil_count < oil_sum) {
        int random_cnt = 0;
        bool loop = false;
        int i, j;
        while (random_cnt < 1000000) {
            random_cnt++;
            i = rand() % (N);
            j = rand() % (N);
            if (!checked[i][j]) break;

            if (random_cnt == 1000) {
                loop = true;
                break;
            }
        }

        if (loop) {
            debug("loop");
            break;
        }

        cout << "q 1 " << i << " " << j << endl;

        int response;
        cin >> response;
        checked[i][j] = true;

        if (response == 0) continue;

        queue<tuple<int, int, int, int>> q;

        has_oil.push_back({i, j});
        oil[i][j] = response;
        oil_count += response;
        if (oil_count >= oil_sum) break;

        if (i > 0 && !checked[i - 1][j]) q.push({i - 1, j, i, j});
        if (i < N - 1 && !checked[i + 1][j]) q.push({i + 1, j, i, j});
        if (j > 0 && !checked[i][j - 1]) q.push({i, j - 1, i, j});
        if (j < N - 1 && !checked[i][j + 1]) q.push({i, j + 1, i, j});

        while (!q.empty()) {
            auto [i, j, pre_i, pre_j] = q.front();
            q.pop();
            if (checked[i][j]) continue;

            int estimated_vS = -1;
            vector<double> data(0);

            rep(mm, 2) {
                cout << "q " << 2 << " " << i << " " << j << " " << pre_i << " " << pre_j << endl;

                int pray;
                cin >> pray;

                pray -= oil[pre_i][pre_j];
                data.push_back(pray);

                // map<int, double> likelihoods;
                // double total_likelihood = 0.0;
                // int k = 2;
                // for (int vS = -1; vS <= M + 1; ++vS) {
                //     double l = likelihood(vS, data, e, k);
                //     likelihoods[vS] = l;
                //     total_likelihood += l;
                // }
                // // 尤度の正規化と最も尤もらしいv(S)の検索
                // double max_probability = 0.0;
                // int best_vS = 0;
                // for (const auto& pair : likelihoods) {
                //     double probability = pair.second / total_likelihood;
                //     if (probability > max_probability) {
                //         max_probability = probability;
                //         best_vS = pair.first;
                //     }
                // }

                // if (max_probability > 0.99) {
                //     if (!check) {
                //         debug(mm);
                //         check = true;
                //     }
                //     estimated_vS = best_vS;
                //     break;
                // }
            }

            map<int, double> likelihoods;
            double total_likelihood = 0.0;
            int k = 2;
            for (int vS = -1; vS <= M + 1; ++vS) {
                double l = likelihood(vS, data, e, k);
                likelihoods[vS] = l;
                total_likelihood += l;
            }
            // 尤度の正規化と最も尤もらしいv(S)の検索
            double max_probability = 0.0;
            int best_vS = 0;
            for (const auto& pair : likelihoods) {
                double probability = pair.second / total_likelihood;
                if (probability > max_probability) {
                    max_probability = probability;
                    best_vS = pair.first;
                }
            }

            estimated_vS = best_vS;

            checked[i][j] = true;

            if (estimated_vS == 0) continue;

            has_oil.push_back({i, j});
            oil[i][j] = estimated_vS;
            oil_count += estimated_vS;
            if (oil_count >= oil_sum) break;

            if (i > 0 && !checked[i - 1][j]) q.push({i - 1, j, pre_i, pre_j});
            if (i < N - 1 && !checked[i + 1][j]) q.push({i + 1, j, pre_i, pre_j});
            if (j > 0 && !checked[i][j - 1]) q.push({i, j - 1, pre_i, pre_j});
            if (j < N - 1 && !checked[i][j + 1]) q.push({i, j + 1, pre_i, pre_j});
        }
    }

    debug(oil_count);

    cout << "a " << has_oil.size() << " ";
    for (auto [i, j] : has_oil) {
        cout << i << " " << j << " ";
    }
    cout << endl;
}