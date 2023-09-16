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

    multiset<char> st;
    set<char> s;
    for (char c : S) {
        st.insert(c);
        s.insert(c);
    }

    if (s.size() != 2) {
        cout << "No" << endl;
        return 0;
    }

    for (char c : st) {
        if (st.count(c) != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}