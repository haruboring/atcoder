#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string N;
    cin >> N;

    if (N[0] == N[1] && N[1] == N[2]) {
        cout << "Yes" << endl;
        return 0;
    }
    if (N[2] == N[3] && N[1] == N[2]) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}
