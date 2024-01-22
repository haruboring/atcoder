#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    string original = S;

    int N = S.size();
    vector<int> order(N - 1);
    rep(i, N - 1) order[i] = i + 1;

    int ans = N;
    do {
        string T = S;
        int watch_time = 0;
        rep(i, N) if (T[i] == 'o') watch_time++;
        rep(i, N - 1) {
            if (watch_time == N) {
                ans = min(ans, i + 1);
                break;
            }

            rep(j, N) {
                if (T[j] == 'o') continue;
                if (original[(j + order[i]) % N] == 'o') {
                    watch_time++;
                    T[j] = 'o';
                }
            }
        }
    } while (next_permutation(all(order)));

    cout << ans << endl;
}
