#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T, A;
    cin >> N >> T >> A;

    if (abs(T-A) > (N-T-A)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}