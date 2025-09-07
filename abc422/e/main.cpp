#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    mt19937 engine{std::random_device{}()};
    uniform_int_distribution<int> dist(0, N);

    rep(_, 100) {
        int i = dist(engine);
        unordered_map<pair<int, int>, int> m;
        int sX = X[i], sY = Y[i];
        rep(j, N) {
            if (i == j) continue;
            int mo = (sY - Y[j]) / gcd((sY - Y[j]), (sX - X[j]));
            int ch = (sX - X[j]) / gcd((sY - Y[j]), (sX - X[j]));
            if (mo < 0) {
                mo *= -1, ch *= -1;
            }
            m[{mo, ch}]++;
        }
        for (auto [k, v] : m) {
            auto [m, c] = k;
            if (v + 1 > N / 2) {
                cout << "Yes" << endl;
                cout << c << " " << m << " " << sY - c * sX << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
