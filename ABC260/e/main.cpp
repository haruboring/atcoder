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
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    rep(i, N) {
        A[i]--;
        B[i]--;
    }

    vector<vector<int>> v(M);
    rep(i, N) {
        v[A[i]].push_back(i);
        v[B[i]].push_back(i);
    }

    vector<int> ans(M);
    multiset<int> s;
    int cnt = 0;
    for (int i = 0, j = 0; i < M;) {
        while (j < M) {
            if (cnt == N) break;
            for (auto x : v[j]) {
                if (!s.count(x)) cnt++;
                s.insert(x);
            }
            j++;
        }
        if (cnt == N) {
            ans[j - i - 1]++;
            if (i != 0) ans[M - i]--;
        }

        for (auto x : v[i]) {
            s.erase(s.find(x));
            if (!s.count(x)) cnt--;
        }
        i++;
    }

    rep(i, M) {
        if (i != 0) ans[i] += ans[i - 1];
        cout << ans[i] << " ";
    }
    cout << endl;
}
