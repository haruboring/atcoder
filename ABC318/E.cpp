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

    int ans = 0;

    map<int, vector<int>> mp;
    vector<int> id(N + 1, 0);
    map<int, int> mp2;
    rep(i, N + 1) {
        mp2[i] = -1;
    }

    rep(i, N) {
        int a = A[i];
        if (mp2[a] == -1) {
            mp2[a] = i;
        } else {
            mp[a].push_back(i - mp2[a] - 1);
            mp2[a] = i;
        }
    }

    debug(N);

    vector<int> sum(N + 1);
    repp(i, 1, N + 1) {
        for (auto x : mp[i]) {
            sum[i] += x;
        }
    }
    vector<int> summ(N + 1);
    repp(i, 1, N + 1) {
        int tmp = mp[i].size();
        for (auto x : mp[i]) {
            summ[i] += x*tmp;
            tmp--;
        }
    }

    vector<int> size(N+1);
    repp(i,1,N+1){
        size[i] = mp[i].size();
    }

    debug(sum[2]);

    rep(i, N) {
        int a = A[i];
        ans += summ[a];
        if (mp[a].size() == 0) continue;
        summ[a] -= mp[a][id[a]] * size[a];
        id[a]++;
        size[a]--;

        debug(ans);
    }

    cout << ans << endl;
}