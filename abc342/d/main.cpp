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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<vector<int>, int> mp;
    int ok_cnt = 0;
    int zero_cnt = 0;
    rep(i, N) {
        if (A[i] == 0) {
            zero_cnt++;
            continue;
        }
        map<int, int> tmp;
        for (int j = 2; j * j <= A[i]; j++) {
            while (A[i] % j == 0) {
                tmp[j]++;
                A[i] /= j;
            }
        }
        if (A[i] != 1) {
            tmp[A[i]]++;
        }
        vector<int> vd;
        for (auto [k, v] : tmp) {
            if (v % 2 == 1) {
                vd.push_back(k);
            }
        }
        if (vd.size() == 0) {
            ok_cnt++;
        }
        mp[vd]++;
    }

    int ans = 0;

    for (auto [k, v] : mp) {
        ans += v * (v - 1) / 2;
    }

    rep(i, zero_cnt) {
        ans += (N - i - 1);
    }

    cout << ans << endl;
}
