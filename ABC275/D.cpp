#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int c(int x1, int y1, int x2, int y2) {
    int c = pow(x1 - x2, 2) + pow(y1 - y2, 2);
    return c;
}

bool sq(int x1, int y1, int x2, int y2, int x11, int y11, int x22, int y22) {
    vector<vector<int>> a(4, vector<int>(3));
    a[0][0] = c(x1, y1, x2, y2);
    a[0][1] = c(x1, y1, x22, y22);
    a[0][2] = c(x1, y1, x11, y11);
    sort(all(a[0]));
    a[1][0] = c(x11, y11, x2, y2);
    a[1][1] = c(x11, y11, x22, y22);
    a[1][2] = c(x11, y11, x1, y1);
    sort(all(a[1]));
    a[2][0] = c(x2, y2, x1, y1);
    a[2][1] = c(x2, y2, x22, y22);
    a[2][2] = c(x2, y2, x11, y11);
    sort(all(a[2]));
    a[3][0] = c(x22, y22, x2, y2);
    a[3][1] = c(x22, y22, x1, y1);
    a[3][2] = c(x22, y22, x11, y11);
    sort(all(a[3]));
    if (a[0][0] == 0 || a[1][0] == 0 || a[2][0] == 0 || a[3][0] == 0) {
        return false;
    }
    if (a[0][0] == a[0][1] && 2 * a[0][1] == a[0][2]) {
        if (a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[2][0] == a[3][0]) {
            if (a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[2][1] == a[3][1]) {
                if (a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[2][2] == a[3][2]) {
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
    vector<string> S(9);
    rep(i, 9) {
        cin >> S[i];
    }
    ll ans = 0;
    rep(xi, 9) {
        rep(yi, 9) {
            rep(xj, 9) {
                rep(yj, 9) {
                    if(xi==xj && yi == yj){
                        break;
                    }
                    rep(xii, 9) {
                        rep(yii, 9) {
                            if(xi==xii && yi == yii){
                                break;
                            }
                            if(xj==xii && yj == yii){
                                break;
                            }
                            rep(xjj, 9) {
                                rep(yjj, 9) {
                                    // (xi, yi), (xj, yj)
                                    if (S[xi][yi] == '#' && S[xj][yj] == '#' && S[xii][yii] == '#' && S[xjj][yjj] == '#') {
                                        if (sq(xi, yi, xj, yj, xii, yii, xjj, yjj)) {
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}