#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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