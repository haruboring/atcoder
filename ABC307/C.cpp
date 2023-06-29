#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int Ha, Wa;
    cin >> Ha >> Wa;
    vector<string> A(Ha);
    rep(i, Ha) cin >> A[i];
    int Hb, Wb;
    cin >> Hb >> Wb;
    vector<string> B(Hb);
    rep(i, Hb) cin >> B[i];
    int Hx, Wx;
    cin >> Hx >> Wx;
    vector<string> X(Hx);
    rep(i, Hx) cin >> X[i];

    int cnt_sharp_in_A = 0, cnt_sharp_in_B = 0;
    rep(i, Ha) rep(j, Wa) if (A[i][j] == '#') cnt_sharp_in_A++;
    rep(i, Hb) rep(j, Wb) if (B[i][j] == '#') cnt_sharp_in_B++;

    repp(i, -Ha, Hx + 1) {
        repp(j, -Wa, Wx + 1) {
            repp(k, -Hb, Hx + 1) {
                repp(l, -Wb, Wx + 1) {
                    vector<string> tmp(Hx, string(Wx, '.'));
                    int cnt_sharp_in_X_from_A = 0, cnt_sharp_in_X_from_B = 0;
                    rep(m, Hx) {
                        rep(n, Wx) {
                            if (m - i >= 0 && n - j >= 0 && m - i < Ha && n - j < Wa && A[m - i][n - j] == '#') {
                                tmp[m][n] = '#';
                                cnt_sharp_in_X_from_A++;
                            }
                            if (m - k >= 0 && n - l >= 0 && m - k < Hb && n - l < Wb && B[m - k][n - l] == '#') {
                                tmp[m][n] = '#';
                                cnt_sharp_in_X_from_B++;
                            }
                        }
                    }

                    bool is_same = true;
                    rep(m, Hx) {
                        rep(n, Wx) {
                            if (X[m][n] != tmp[m][n]) {
                                is_same = false;
                            }
                        }
                    }

                    if (is_same && cnt_sharp_in_A == cnt_sharp_in_X_from_A && cnt_sharp_in_B == cnt_sharp_in_X_from_B) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
}