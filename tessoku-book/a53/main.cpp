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

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else if (f == 2) {
            int a = pq.top();
            cout << a << endl;
        } else {
            pq.pop();
        }
    }
}
