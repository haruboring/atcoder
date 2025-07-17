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

    queue<int> q;
    rep(_, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int X;
            cin >> X;
            q.push(X);
        } else {
            cout << q.front() << endl;
            q.pop();
        }
    }
}
