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
    string S;
    cin >> S;

    N = pow(3, N);

    vector<int> V(N);
    rep(i, N) V[i] = S[i] - '0';
    while (V.size() > 1) {
        int size = V.size();
        vector<int> nV(size / 3);
        rep(i, size / 3) {
            int c0 = 0, c1 = 0;
            rep(j, 3) {
                if (V[i * 3 + j] == 0) {
                    c0++;
                } else {
                    c1++;
                }
            }
            if (c0 > c1) {
                nV[i] = 0;
            } else {
                nV[i] = 1;
            }
        }
        V = nV;
    }

    int a1 = V[0];
    debug(a1);
    int ra1 = 1 - a1;
    debug(ra1);

    vector<int> C(N, 1);
    V = vector<int>(N);
    rep(i, N) V[i] = S[i] - '0';
    debug(V.size());
    while (V.size() > 1) {
        int size = V.size();
        vector<int> nV(size / 3), nC(size / 3);
        rep(i, size / 3) {
            int c0 = 0, c1 = 0;
            vector<int> cost(3);
            rep(j, 3) {
                if (V[i * 3 + j] == 0) {
                    c0++;
                } else {
                    c1++;
                }
                cost[j] = C[i * 3 + j];
                if (V[i * 3 + j] == ra1) cost[j] = 1e9;
            }

            sort(all(cost));
            if (c0 > c1) {
                nV[i] = 0;
                if (ra1 == 1) {
                    if (c0 == 2) {
                        nC[i] += cost[0];
                    } else {
                        nC[i] += cost[0] + cost[1];
                    }
                }
            } else {
                nV[i] = 1;
                if (ra1 == 0) {
                    if (c1 == 2) {
                        nC[i] += cost[0];
                    } else {
                        nC[i] += cost[0] + cost[1];
                    }
                }
            }
        }

        // cout << "C: ";
        // rep(i, C.size()) {
        //     cout << C[i] << " ";
        // }
        // cout << endl;

        // cout << "V: ";
        // rep(i, V.size()) {
        //     cout << V[i] << " ";
        // }
        // cout << endl;

        V = nV;
        C = nC;
    }

    cout << C[0] << endl;
}
