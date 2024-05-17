#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    map<int, vector<int>> mp;
    vector<vector<int>> v(N, vector<int>(0));
    rep(i, N) {
        int C;
        cin >> C;
        rep(j, C) {
            int A;
            cin >> A;
            mp[A].push_back(C);
            v[i].push_back(A);
        }
    }
    rep(i, 37) {
        sort(all(mp[i]));
    }

    int X;
    cin >> X;
    if (mp[X].size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int m = mp[X][0];

    vector<int> ans(0);
    int cnt = 0;
    rep(i, N) {
        if (v[i].size() != m) continue;
        bool b = false;
        rep(j, v[i].size()) {
            if (v[i][j] == X) {
                cnt++;
                ans.push_back(i + 1);
            }
        }
    }

    cout << cnt << endl;
    rep(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
}