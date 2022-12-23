#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<double> R(N);
    rep(i, N) {
        cin >> R[i];
    }
    sort(all(R));
    reverse(all(R));
    double rate = 0;
    rep(i, K) {
        rate = (rate + R[K - i - 1]) / 2;
    }
    cout << fixed << setprecision(10) << rate << endl;
}