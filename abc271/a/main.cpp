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
    stringstream s;
    s << hex << N;
    string ss = s.str();
    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
    if (ss.size() == 1) {
        cout << 0 << ss << endl;
    } else {
        cout << ss << endl;
    }
}