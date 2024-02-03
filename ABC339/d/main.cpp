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
    vector<string> S(N), oS(N);
    rep(i, N) {
        cin >> S[i];
    }

    int opos_A_i = -1, opos_A_j = -1, opos_B_i = -1, opos_B_j = -1;
    rep(i, N) {
        rep(j, N) {
            if (opos_A_i == -1 && S[i][j] == 'P') {
                opos_A_i = i;
                opos_A_j = j;
            } else if (S[i][j] == 'P') {
                opos_B_i = i;
                opos_B_j = j;
            }
        }
    }

    S[opos_A_i][opos_A_j] = '.';
    S[opos_B_i][opos_B_j] = '.';

    rep(i, N) {
        oS[i] = S[i];
    }

    vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<int> orders = {0, 1, 2, 3};
    sort(all(orders));

    int ans = 1e9;
    do {
        S = oS;
        int pos_A_i = opos_A_i, pos_A_j = opos_A_j, pos_B_i = opos_B_i, pos_B_j = opos_B_j;
        int cnt = 0;
        rep(i, 4) {
            while (1) {
                if (pos_A_i == pos_B_i && pos_A_j == pos_B_j) {
                    ans = min(ans, cnt);
                    break;
                }

                int npos_A_i = pos_A_i + moves[orders[i]][0];
                int npos_A_j = pos_A_j + moves[orders[i]][1];
                int npos_B_i = pos_B_i + moves[orders[i]][0];
                int npos_B_j = pos_B_j + moves[orders[i]][1];

                bool unmove = true;
                if (npos_A_i >= 0 && npos_A_i < N && npos_A_j >= 0 && npos_A_j < N && S[npos_A_i][npos_A_j] == '.') {
                    pos_A_i = npos_A_i;
                    pos_A_j = npos_A_j;
                    unmove = false;
                }
                if (npos_B_i >= 0 && npos_B_i < N && npos_B_j >= 0 && npos_B_j < N && S[npos_B_i][npos_B_j] == '.') {
                    pos_B_i = npos_B_i;
                    pos_B_j = npos_B_j;
                    unmove = false;
                }
                if (!unmove) {
                    cnt++;
                }
                if (unmove) {
                    break;
                }
            }
        }
    } while (next_permutation(all(orders)));

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

/*
5
P....
P....
.....
.....
.....
*/
