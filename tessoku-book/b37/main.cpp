#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    debug(4 * pow(10, 17));
    int N;
    cin >> N;

    vector<int> T(20);
    T[0] = 0;
    T[1] = 45;
    repp(i, 2, 20) T[i] = 45 * powl(10, i - 1) * i;

    int ans = 0;
    string S = to_string(N);
    debug(S.size());
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S[i] - '0'; j++) ans += j * powl(10, S.size() - 1 - i) + T[S.size() - 1 - i];
        ans += (S[i] - '0') * (N % (int)pow(10LL, S.size() - 1 - i) + 1);
    }

    cout << ans << endl;
}
