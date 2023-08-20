#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    // 乱数エンジンの初期化
    std::random_device rd;
    std::mt19937 gen(rd());

    double S = 500;                      // 例として標準偏差を1.0に設定
    std::normal_distribution<> d(0, S);  // 平均0、標準偏差Sの正規分布

    const int N = 100;
    double sum = 0.0;
    int cnt = N;

    // 正規分布からランダムな値を1000回取り出す
    for (int i = 0; i < N; ++i) {
        double value = d(gen);
        // if(value < 0){
        //     value = 0;
        // }
        // if(value > 1000){
        //     value = 1000;
        // }
        cout << value << endl;

        if (abs(value) > 2 * S) {
            cnt--;
            continue;
        }
        sum += value;
    }

    debug(sum / cnt);  // 平均は0に近いはず

    return 0;
}
