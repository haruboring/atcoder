#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }
    int max_cnt = 0;
    rep(i, 1 << N) {
        bitset<16> s(i);
        int cnt_K = 0;
        vector<int> al('z' - 'a' + 1);
        rep(j, N) {
            if (s.test(j)) {
                rep(k, S[j].size()) {
                    al[S[j][k] - 'a']++;
                }
            }
        }
        rep(j, 'z' - 'a' + 1) {
            if (al[j] == K) {
                cnt_K++;
            }
        }
        max_cnt = max(cnt_K, max_cnt);
    }
    cout << max_cnt << endl;
}