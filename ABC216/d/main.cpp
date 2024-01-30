#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<queue<int>> tutu(M);
    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            tutu[i].push(a);
        }
    }

    queue<int> q;

    map<int, vector<int>> mp;
    rep(i, M) {
        int a = tutu[i].front();
        mp[a].push_back(i);
        if (mp[a].size() == 2) q.push(a);
    }

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto i : mp[a]) {
            tutu[i].pop();
            if (!tutu[i].empty()) {
                int b = tutu[i].front();
                mp[b].push_back(i);
                if (mp[b].size() == 2) q.push(b);
            }
        }
    }

    bool ok = true;
    rep(i, M) {
        if (!tutu[i].empty()) ok = false;
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
