
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int cnt_E = 0, cnt_W = 0;
    rep(i, N) if (S[i] == 'E') cnt_E++;
    vector<int> all_E(N, 0), all_W(N, 0);
    rep(i, N) {
        if (S[i] == 'E') cnt_E--;
        all_E[i] = cnt_E;
        all_W[i] = cnt_W;
        if (S[i] == 'W') cnt_W++;
    }

    int ans = 1e9;
    rep(i, N) {
        ans = min(ans, all_E[i] + all_W[i]);
    }

    cout << ans << endl;
}