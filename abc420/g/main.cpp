#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int X;
    cin >> X;

    int a = 4 * X - 1;
    set<int> s;
    for (int i = 1; i * i <= abs(a); i += 2) {
        if (a % i) continue;
        int b = a / i;
        if ((i - b - 2) % 4 == 0) s.insert((i - b - 2) / 4);
        if ((b - i - 2) % 4 == 0) s.insert((b - i - 2) / 4);
    }

    cout << s.size() << endl;
    for (auto ss : s) cout << ss << " ";
    cout << endl;
}