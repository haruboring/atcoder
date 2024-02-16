#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

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
    // 与えられたデータ
    vector<double> data = {1.5};
    double epsilon = 0.04;
    double k = 2;

    std::map<int, double> likelihoods;
    double total_likelihood = 0.0;

    // 各v(S)に対する尤度の計算
    for (int vS = -5; vS <= 5; ++vS) {
        double l = likelihood(vS, data, epsilon, k);
        likelihoods[vS] = l;
        total_likelihood += l;
    }

    // 尤度の正規化と最も尤もらしいv(S)の検索
    double max_probability = 0.0;
    int best_vS = 0;
    for (const auto& pair : likelihoods) {
        double probability = pair.second / total_likelihood;
        std::cout << "v(S) = " << pair.first << ": Probability = " << probability << std::endl;
        if (probability > max_probability) {
            max_probability = probability;
            best_vS = pair.first;
        }
    }

    debug(max_probability);

    std::cout << "Most likely v(S) = " << best_vS << std::endl;

    return 0;
}