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
    string S, T;
    cin >> S >> T;

    int sl = S.size(), tl = T.size();
    vector<vector<int>> pos(26);
    rep(i, 2 * sl) pos[S[i % sl] - 'a'].push_back(i);
    vector<vector<int>> pre(sl + 1, vector<int>(26));
    rep(i, sl) {
        pre[i + 1] = pre[i];
        pre[i + 1][S[i] - 'a']++;
    }

    vector<int> cnt(26);
    rep(i, 26) cnt[i] = pos[i].size() / 2;
    int ok = 0, ng = 1e18;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        bool ok_flag = true;

        int iter = 0;
        rep(i, tl) {
            int c = T[i] - 'a';
            if (cnt[c] == 0) {
                ok_flag = false;
                break;
            }

            int r = (mid - 1) % cnt[c] + 1;
            int q = (mid - r) / cnt[c];
            if (q > 1e18 / sl) {
                ok_flag = false;
                break;
            }

            iter += sl * q;

            int nx = pos[c][pre[iter % sl][c] + r - 1];
            iter += nx + 1 - iter % sl;
            if (iter > N * sl) {
                ok_flag = false;
                break;
            }
        }

        if (ok_flag)
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;
}
