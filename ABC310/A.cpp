#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> D(N);
    rep(i, N) cin >> D[i];

    sort(all(D));

    cout << min(P, Q + D[0]) << endl;
}