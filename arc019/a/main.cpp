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

    map<char, char> mp;
    mp['O'] = '0', mp['D'] = '0', mp['I'] = '1', mp['Z'] = '2', mp['S'] = '5', mp['B'] = '8';

    for (char c : S) {
        if (mp.count(c)) {
            cout << mp[c];
        } else {
            cout << c;
        }
    }
    cout << endl;
}
