#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    char p, q;
    cin >> p >> q;

    map<char, int> mp;
    mp['A'] = 0;
    mp['B'] = 3;
    mp['C'] = 4;
    mp['D'] = 8;
    mp['E'] = 9;
    mp['F'] = 14;
    mp['G'] = 23;
    cout << abs(mp[q] - mp[p]) << endl;
}