#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int M;
    cin >> M;
    vector<int> D(M);
    rep(i, M) cin >> D[i];

    set<int> ds;
    rep(i, M) ds.insert(D[i]);

    int all_days = 0;
    rep(i, M) all_days += D[i];
    int half_days = (all_days + 1) / 2;
    rep(i, M) {
        rep(j, D[i]) {
            half_days--;
            if (half_days == 0) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    for(auto )
}