#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    set<int> S;
    S.insert(A);
    S.insert(B);
    S.insert(C);
    S.insert(D);
    S.insert(E);
    cout << S.size() << endl;
}