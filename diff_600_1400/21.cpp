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
    vector<ll> R(N, 0), G(N, 0), B(N, 0);
    ll r = 0, g = 0, b = 0;
    rep(i, N) {
        if (S[i] == 'R') {
            r++;
        }
        if (S[i] == 'G') {
            g++;
        }
        if (S[i] == 'B') {
            b++;
        }
        R[i] = r;
        G[i] = g;
        B[i] = b;
    }

    ll cnt = 0;
    rep(i, N - 2) {
        if (S[i] == 'R') {
            repp(j, i + 1, N - 1) {
                if (S[j] == 'G') {
                    if (j + (j - i) < N && S[j + (j - i)] == 'B') {
                        cnt--;
                    }
                    cnt += B[N - 1] - B[j];
                }
                if (S[j] == 'B') {
                    if (j + (j - i) < N && S[j + (j - i)] == 'G') {
                        cnt--;
                    }
                    cnt += G[N - 1] - G[j];
                }
            }
        }
        if (S[i] == 'G') {
            repp(j, i + 1, N - 1) {
                if (S[j] == 'R') {
                    if (j + (j - i) < N && S[j + (j - i)] == 'B') {
                        cnt--;
                    }
                    cnt += B[N - 1] - B[j];
                }
                if (S[j] == 'B') {
                    if (j + (j - i) < N && S[j + (j - i)] == 'R') {
                        cnt--;
                    }
                    cnt += R[N - 1] - R[j];
                }
            }
        }
        if (S[i] == 'B') {
            repp(j, i + 1, N - 1) {
                if (S[j] == 'R') {
                    if (j + (j - i) < N && S[j + (j - i)] == 'G') {
                        cnt--;
                    }
                    cnt += G[N - 1] - G[j];
                }
                if (S[j] == 'G') {
                    if (j + (j - i) < N && S[j + (j - i)] == 'R') {
                        cnt--;
                    }
                    cnt += R[N - 1] - R[j];
                }
            }
        }
    }

    cout << cnt << endl;
}