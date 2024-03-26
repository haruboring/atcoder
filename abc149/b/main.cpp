#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, K;
    cin >> A >> B >> K;

    cout << max(0LL, A - K) << " " << max(0LL, B - K + A - max(0LL, A - K)) << endl;
}
