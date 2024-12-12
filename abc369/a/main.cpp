#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B;
    cin >> A >> B;

    if (A > B) swap(A, B);

    set<int> s;
    s.insert(B + (B - A));
    s.insert(A - (B - A));
    if ((A + B) % 2 == 0) s.insert((A + B) / 2);

    cout << s.size() << endl;
}
