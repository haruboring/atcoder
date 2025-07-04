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
    map<string, int> m;
    rep(i, N) {
        string S;
        cin >> S;
        if (m[S] == 0) {
            cout << S << endl;
        } else {
            cout << S << "(" << m[S] << ")" << endl;
        }
        m[S]++;
    }
}
