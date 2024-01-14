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
    vector<int> t(N), x(N);
    rep(i, N) cin >> t[i] >> x[i];

    map<int, int> mp;

    rep(i, N) {
        if (t[i] == 1) {
            mp[x[i]]++;
        } else {
            mp[x[i]]--;
            if (mp[x[i]] < 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    mp.clear();
    vector<int> ans(0);
    int max_K = 0;
    int sum = 0;
    rep(i, N) {
        if (t[N - 1 - i] == 2) {
            mp[x[N - 1 - i]]--;
            sum++;
        } else {
            if (mp[x[N - 1 - i]] < 0) {
                mp[x[N - 1 - i]]++;
                sum--;
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }

        max_K = max(max_K, sum);
    }

    cout << max_K << endl;
    rep(i, ans.size()) {
        cout << ans[ans.size() - 1 - i] << " ";
    }
    cout << endl;
}
