// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T, g;
    cin >> N >> T >> g;
    vector<int> w(N), h(N);
    rep(i, N) cin >> w[i] >> h[i];

    rep(i, T) {
        int max_h = 0;
        vector<int> ww = w, hh = h;
        vector<bool> swapped(N, false);
        rep(i, N) {
            // ランダムにww, hhを入れ替える
            int j = rand() % 2;
            if (j == 0) {
                swap(ww[i], hh[i]);
                swapped[i] = true;
            }
        }
        rep(j, N) max_h = max(max_h, hh[j]);
        max_h *= i + 1;
        int sum = 0;
        cout << N << endl;
        rep(j, N) {
            sum += h[j];
            int p = j;
            int r = 0;
            if (swapped[j]) r = 1;
            char d = 'L';
            int b = j - 1;
            if (sum > max_h) {
                b = -1;
                sum = 0;
            }

            cout << p << " " << r << " " << d << " " << b << endl;
        }
    }
}

/*
n
p0, r0, d0, b0
*/