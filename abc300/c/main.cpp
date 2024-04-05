#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    rep(i, H) {
        cin >> C[i];
    }
    int N = min(H, W);
    vector<int> A(N + 2);
    rep(i, H) {
        rep(j, W) {
            int len = 0;
            rep(k, N) {
                if (i + k < H && i - k >= 0 && j + k < W && j - k >= 0) {
                    if (C[i + k][j + k] == '#' && C[i + k][j - k] == '#' && C[i - k][j + k] == '#' && C[i - k][j - k] == '#') {
                        len++;
                    } else {
                        break;
                    }
                }
            }
            A[len]++;
        }
    }
    repp(i, 2, N + 2) {
        cout << A[i] << " ";
    }
    cout << endl;
}