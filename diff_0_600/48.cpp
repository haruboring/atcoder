#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int x, y;
    cin >> x >> y;

    set<int> s1 = {1, 3, 5, 7, 8, 10, 12};
    set<int> s2 = {4, 6, 9, 11};
    set<int> s3 = {2};

    if (s1.count(x) && s1.count(y))
        cout << "Yes" << endl;
    else if (s2.count(x) && s2.count(y))
        cout << "Yes" << endl;
    else if (s3.count(x) && s3.count(y))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}