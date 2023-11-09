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

    int cnt = 0;

    rep(_, N) {
        string S;
        cin >> S;

        if (S == "black") cnt++;
    }
    if (cnt > N / 2)
        cout << "black" << endl;
    else
        cout << "white" << endl;
}