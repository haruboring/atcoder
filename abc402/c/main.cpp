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

    map<int, vector<int>> zai2ryo, ryo2zai;
    map<int, set<int>> ryo2unetable_zai;
    rep(i, M) {
        int K;
        cin >> K;
        vector<int> A(K);
        rep(j, K) cin >> A[j];

        rep(j, K) {
            zai2ryo[A[j]].push_back(i + 1);
            ryo2unetable_zai[i + 1].insert(A[j]);
        }
    }

    vector<int> B(N);
    rep(i, N) cin >> B[i];

    int cnt = 0;
    rep(i, N) {
        int zai = B[i];

        for (int ryo : zai2ryo[zai]) {
            if (!ryo2unetable_zai[ryo].count(zai)) continue;
            ryo2unetable_zai[ryo].erase(zai);
            if (ryo2unetable_zai[ryo].size() == 0) cnt++;
        }

        cout << cnt << endl;
    }
}
