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
    string S;
    cin >> S;

    map<int, list<int>::iterator> mp;
    list<int> ls;
    ls.push_back(0);
    auto itr = ls.begin();
    mp[0] = itr;

    rep(i, N) {
        if (S[i] == 'R') {
            auto itr = mp[i];
            advance(itr, 1);
            mp[i + 1] = ls.insert(itr, i + 1);
        } else {
            auto itr = mp[i];
            // advance(itr, -1);
            mp[i + 1] = ls.insert(itr, i + 1);
        }
    }

    for (int a : ls) {
        cout << a << " ";
    }
    cout << endl;
}
