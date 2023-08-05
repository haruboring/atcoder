#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> T(N, vector<int>(K));
    rep(i, N) {
        rep(j, K) {
            cin >> T[i][j];
        }
    }
    int a = 1;
    rep(i, N) {
        a *= K;
    }
    rep(i, a + 1) {
        int ci = i;
        string k_sinsu = "";
        rep(j, N) {
            k_sinsu += to_string(ci % K);
            ci /= K;
        }
        int xr = 0;
        rep(j, N) {
            xr ^= T[j][k_sinsu[j] - '0'];
        }
        if (xr == 0) {
            cout << "Found" << endl;
            return 0;
        }
    }
    cout << "Nothing" << endl;
}