#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    stack<int> l;
    rep(i, S.size()) {
        if (S[i] == '(') {
            l.push(i);
        } else {
            cout << l.top() + 1 << " " << i + 1 << endl;
            l.pop();
        }
    }
}
