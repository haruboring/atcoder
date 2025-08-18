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

    if (S == "red") {
        cout << "SSS" << endl;
    } else if (S == "blue") {
        cout << "FFF" << endl;
    } else if (S == "green") {
        cout << "MMM" << endl;
    } else {
        cout << "Unknown" << endl;
    }
}
