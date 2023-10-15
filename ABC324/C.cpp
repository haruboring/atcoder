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
    string T;
    cin >> T;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> ans(0);

    rep(i, N) {
        if (T == S[i]) {
            ans.push_back(i + 1);
        } else if (T.size() == S[i].size() + 1) {
            int cnt = 0;
            int ind = -1;
            rep(j, T.size()) {
                if (T[j] != S[i][j - cnt]) {
                    cnt++;
                    if (cnt == 2) {
                        break;
                    }
                    ind = j;
                }
            }
            if (cnt == 1 && islower(T[ind])) {
                ans.push_back(i + 1);
            }
        } else if (T.size() == S[i].size() - 1) {
            int cnt = 0;
            int ind = -1;
            rep(j, S[i].size()) {
                if (T[j - cnt] != S[i][j]) {
                    cnt++;
                    if (cnt == 2) {
                        break;
                    }
                    ind = j;
                }
            }

            if (cnt == 1) {
                ans.push_back(i + 1);
            }
        } else if (T.size() == S[i].size()) {
            int cnt = 0;
            rep(j, T.size()) {
                if (T[j] == S[i][j]) continue;
                cnt++;
            }
            if (cnt == 1) {
                ans.push_back(i + 1);
            }
        }
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
}