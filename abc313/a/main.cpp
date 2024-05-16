#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P.at(i);

    int ma = -1;
    repp(i, 1, N) {
        ma = max(ma, P.at(i));
    }
    cout << max(ma - P[0] + 1, 0) << endl;
}