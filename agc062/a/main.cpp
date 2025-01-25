#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;
    rep(_, T) {
        int N;
        string S;
        cin >> N >> S;

        if (S[N - 1] == 'A') {
            cout << 'A' << endl;
        } else {
            string sS = S;
            sort(all(sS));
            if (sS == S) {
                cout << 'B' << endl;
            } else {
                cout << 'A' << endl;
            }
        }
    }
}
