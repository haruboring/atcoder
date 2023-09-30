#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<string> P1(4), P2(4), P3(4);
    rep(i, 4) cin >> P1[i];
    rep(i, 4) cin >> P2[i];
    rep(i, 4) cin >> P3[i];

    int cnt = 0;
    rep(i, 4) rep(j, 4) {
        if (P1[i][j] == '#') cnt++;
        if (P2[i][j] == '#') cnt++;
        if (P3[i][j] == '#') cnt++;
    }
    if (cnt != 16) {
        cout << "No" << endl;
        return 0;
    }

    for (int rt1 = 0; rt1 < 4; rt1++) {
        vector<string> tmp_S2(4, "....");
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                tmp_S2[a][b] = P2[3 - b][a];
            }
        }
        for (int rt2 = 0; rt2 < 4; rt2++) {
            vector<string> tmp_S3(4, "....");
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    tmp_S3[a][b] = P3[3 - b][a];
                }
            }

            P2 = tmp_S2;
            P3 = tmp_S3;

            for (int dx1 = -4; dx1 < 4; dx1++) {
                for (int dy1 = -4; dy1 < 4; dy1++) {
                    for (int dx2 = -4; dx2 < 4; dx2++) {
                        for (int dy2 = -4; dy2 < 4; dy2++) {
                            for (int dx3 = -4; dx3 < 4; dx3++) {
                                for (int dy3 = -4; dy3 < 4; dy3++) {
                                    vector<string> tmp(4, "....");

                                    bool is_valid = true;
                                    for (int i = 0; i < 4; i++) {
                                        for (int j = 0; j < 4; j++) {
                                            if (P1[i][j] == '#') {
                                                int x = i + dx1;
                                                int y = j + dy1;
                                                if (0 <= x && x < 4 && 0 <= y && y < 4) {
                                                    if (tmp[x][y] == '#') is_valid = false;
                                                    tmp[x][y] = '#';
                                                } else {
                                                    is_valid = false;
                                                }
                                            }
                                        }
                                    }

                                    if (!is_valid) continue;

                                    for (int i = 0; i < 4; i++) {
                                        for (int j = 0; j < 4; j++) {
                                            if (P2[i][j] == '#') {
                                                int x = i + dx2;
                                                int y = j + dy2;
                                                if (0 <= x && x < 4 && 0 <= y && y < 4) {
                                                    if (tmp[x][y] == '#') is_valid = false;
                                                    tmp[x][y] = '#';
                                                } else {
                                                    is_valid = false;
                                                }
                                            }
                                        }
                                    }

                                    if (!is_valid) continue;

                                    for (int i = 0; i < 4; i++) {
                                        for (int j = 0; j < 4; j++) {
                                            if (P3[i][j] == '#') {
                                                int x = i + dx3;
                                                int y = j + dy3;
                                                if (0 <= x && x < 4 && 0 <= y && y < 4) {
                                                    if (tmp[x][y] == '#') is_valid = false;
                                                    tmp[x][y] = '#';
                                                } else {
                                                    is_valid = false;
                                                }
                                            }
                                        }
                                    }

                                    if (is_valid) {
                                        cout << "Yes" << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
}