#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> m(N);
    vector<vector<pair<int, int>>> p_e(200000 + 100, vector<pair<int, int>>(0));
    map<pair<int, int>, int> cnt_p_e;
    map<int, int> LCM;
    rep(i, N) {
        cin >> m[i];
        rep(j, m[i]) {
            int p, e;
            cin >> p >> e;
            p_e[i].push_back(make_pair(p, e));
            cnt_p_e[make_pair(p, e)]++;
            LCM[p] = max(LCM[p], e);
        }
    }

    ll ans = 0;
    set<set<int>> Ss;

    rep(i, N) {
        set<int> S;
        for (auto p_e : p_e[i]) {
            int p = p_e.first;
            int e = p_e.second;

            if (LCM[p] == e && cnt_p_e[make_pair(p, e)] == 1) {
                S.insert(p);
            }
        }
        if (Ss.count(S) == 0) {
            ans++;
        }
        Ss.insert(S);
    }
    cout << ans << endl;
}
