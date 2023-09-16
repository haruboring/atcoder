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
    vector<int> a(M);
    rep(i, M) {
        a[i] = i + 1;
    }
    set<vector<int>> S;
    do {
        vector<int> Ss(0);
        vector<int> memo(0);
        for (int i = 0; i < N; i++) {
            Ss.push_back(a[i]);
            memo.push_back(a[i]);
        }
        sort(all(Ss));
        int bef_S_size = S.size();
        S.insert(Ss);
        int aft_S_size = S.size();
        if (bef_S_size != aft_S_size) {
            rep(i, N) {
                cout << memo[i] << " ";
            }
            cout << endl;
        }
    } while (next_permutation(all(a)));
}