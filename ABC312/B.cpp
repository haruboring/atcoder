#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<pair<int, int>> ans;
    rep(i, N - 8) {
        rep(j, M - 8) {
            bool flag = true;
            rep(k, 9) {
                rep(l, 9) {
                    if (k < 3 && l < 3) {
                        if (S[i + k][j + l] != '#') {
                            flag = false;
                        }
                    }
                    if (k == 3 && l < 4) {
                        if (S[i + k][j + l] != '.') {
                            flag = false;
                        }
                    }
                    if (l == 3 && k < 4) {
                        if (S[i + k][j + l] != '.') {
                            flag = false;
                        }
                    }

                    if (k > 8 - 3 && l > 8 - 3) {
                        if (S[i + k][j + l] != '#') {
                            flag = false;
                        }
                    }
                    if (k == 8 - 3 && l > 8 - 4) {
                        if (S[i + k][j + l] != '.') {
                            flag = false;
                        }
                    }
                    if (l == 8 - 3 && k > 8 - 4) {
                        if (S[i + k][j + l] != '.') {
                            flag = false;
                        }
                    }
                }
            }
            if (flag) {
                ans.push_back(make_pair(i + 1, j + 1));
            }
        }
    }

    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}