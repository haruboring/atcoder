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

    stack<string> st;
    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            string x;
            cin >> x;
            st.push(x);
        } else if (f == 2) {
            cout << st.top() << endl;
        } else {
            st.pop();
        }
    }
}
