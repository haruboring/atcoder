#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    if (A + B + C == 0) {
        cout << "No" << endl;
        return 0;
    }
    if (A + B + C == 1) {
        vector<char> ans(N);
        rep(i, N) {
            if (S[i] == "AB") {
                if (A + B == 0) {
                    cout << "No" << endl;
                    return 0;
                }
                if (A == 1) {
                    ans[i] = 'B';
                    A = 0;
                    B = 1;
                } else {
                    ans[i] = 'A';
                    B = 0;
                    A = 1;
                }
            }
            if (S[i] == "BC") {
                if (B + C == 0) {
                    cout << "No" << endl;
                    return 0;
                }
                if (B == 1) {
                    ans[i] = 'C';
                    B = 0;
                    C = 1;
                } else {
                    ans[i] = 'B';
                    C = 0;
                    B = 1;
                }
            }
            if (S[i] == "AC") {
                if (A + C == 0) {
                    cout << "No" << endl;
                    return 0;
                }
                if (A == 1) {
                    ans[i] = 'C';
                    A = 0;
                    C = 1;
                } else {
                    ans[i] = 'A';
                    C = 0;
                    A = 1;
                }
            }
        }
        cout << "Yes" << endl;
        rep(i, N) cout << ans[i] << endl;
        return 0;
    }

    vector<char> ans(N);
    map<char, int> mp;
    mp['A'] = A;
    mp['B'] = B;
    mp['C'] = C;
    rep(i, N) {
        char x = S[i][0], y = S[i][1];
        if (mp[x] <= 0 && mp[y] <= 0) {
            cout << "No" << endl;
            return 0;
        }

        if (mp[x] == 0) {
            ans[i] = x;
            mp[x]++;
            mp[y]--;
        } else if (mp[y] == 0) {
            ans[i] = y;
            mp[y]++;
            mp[x]--;
        } else if (mp[x] == mp[y] && mp[x] == 1) {
            if (i == N - 1) {
                ans[i] = x;
                continue;
            }
            char z = S[i + 1][0], w = S[i + 1][1];
            if (x == z || x == w) {
                ans[i] = x;
                mp[x]++;
                mp[y]--;
            } else {
                ans[i] = y;
                mp[y]++;
                mp[x]--;
            }
        } else if (mp[x] > mp[y]) {
            ans[i] = y;
            mp[y]++;
            mp[x]--;
        } else {
            ans[i] = x;
            mp[x]++;
            mp[y]--;
        }
    }

    cout << "Yes" << endl;
    rep(i, N) cout << ans[i] << endl;
}