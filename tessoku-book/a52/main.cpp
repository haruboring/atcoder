#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;

    queue<string> q;
    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            string s;
            cin >> s;

            q.push(s);
        } else if (f == 2) {
            cout << q.front() << endl;
        } else {
            q.pop();
        }
    }
}
