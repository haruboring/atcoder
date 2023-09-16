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
    vector<int> P(N - 1);
    rep(i, N - 1) {
        cin >> P[i];
    }
    int cnt = 0;
    int history = N - 2;
    while (1) {
        if (P[history] == 1) {
            cnt++;
            break;
        }
        history = P[history] - 2;
        cnt++;
    }
    cout << cnt << endl;
}