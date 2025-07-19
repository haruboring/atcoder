#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

long long combi(long long n, long long k) {
    if (n == k || k == 0)
        return 1;
    else {
        return combi(n - 1, k - 1) + combi(n - 1, k);
    }
}

signed main() {
    int T;
    cin >> T;

    rep(_, T) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        queue<int> q;
        q.push(0);
        vector<bool> used((1 << N), false);
        used[0] = true;

        set<int> s;
        rep(i, S.size()) {
            if (S[i] == '1') s.insert(i + 1);
        }

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            rep(ta, N) {
                int na = a | (1 << ta);
                if (na == a) continue;
                if (used[na] == true) continue;
                if (s.count(na)) continue;
                used[na] = true;
                q.push(na);
            }
        }

        if (used[(1 << N) - 1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
