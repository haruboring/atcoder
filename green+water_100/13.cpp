#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int N = S.length();
    vector<int> cnt(2019 + 1);

    ll ans = 0;
    cnt[0] = 1;
    int temp = 0;
    int d = 1;
    reverse(all(S));
    rep(i, N) {
        temp += d * (S[i] - '0');

        temp %= 2019;

        cnt[temp]++;
        d = (d * 10) % 2019;
    }
    rep(i, 2019 + 1) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
        // cout << cnt[i] << endl;
    }
    cout << ans << endl;
}