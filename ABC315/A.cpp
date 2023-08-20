#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    set<char> st;
    st.insert('a');
    st.insert('i');
    st.insert('u');
    st.insert('e');
    st.insert('o');

    rep(i, s.size()) {
        if (st.count(s[i])) continue;
        cout << s[i];
    }
    cout << endl;
}