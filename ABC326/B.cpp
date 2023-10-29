#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    while (1) {
        string s = to_string(N);
        int tm = s[0] - '0';
        tm *= s[1] - '0';
        if (tm == s[2] - '0') {
            cout << N << endl;
            return 0;
        }
        N++;
    }
}