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
    if (N < 60) {
        cout << "Bad" << endl;
    } else if (N < 90) {
        cout << "Good" << endl;
    } else if (N < 100) {
        cout << "Great" << endl;
    } else {
        cout << "Perfect" << endl;
    }
}