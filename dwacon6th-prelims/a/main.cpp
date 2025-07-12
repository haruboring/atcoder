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
    vector<string> S(N);
    vector<int> T(N);
    rep(i, N) cin >> S[i] >> T[i];
    string X;
    cin >> X;

    int sum = 0;
    bool a = false;
    rep(i, N) {
        string s = S[i];
        int t = T[i];
        if (a) sum += t;
        if (s == X) a = true;
    }

    cout << sum << endl;
}
