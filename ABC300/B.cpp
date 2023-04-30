#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H), B(H);
    rep(i, H) {
        cin >> A[i];
    }
    rep(i, H) {
        cin >> B[i];
    }
    rep(s_cnt, H) {
        rep(t_cnt, W) {
            bool b = true;
            rep(i, H) {
                rep(j, W) {
                    if (A[(i + s_cnt) % H][(j + t_cnt) % W] != B[i][j]) {
                        b = false;
                        break;
                    }
                }
                if (!b) {
                    break;
                }
            }
            if (b) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}