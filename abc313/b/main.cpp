#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A.at(i) >> B.at(i);

    vector<vector<int>> G(N);
    rep(i, M) {
        G.at(B.at(i) - 1).push_back(A.at(i) - 1);
    }

    int cnt = 0;
    int ans = -1;
    rep(i, N) {
        if (G.at(i).size() == 0) {
            cnt++;
            ans = i;
        }
    }
    if (cnt == 1) {
        cout << ans + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}