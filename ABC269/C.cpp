#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll Ncopy = N;
    vector<ll> ans(0);
    ans.push_back(0);
    ll bit_cnt = 1;
    while (1) {
        if (bit_cnt > Ncopy) {
            break;
        }
        if (N % 2 == 1) {
            int size = ans.size();
            rep(i, size) {
                ans.push_back(ans[i] + bit_cnt);
            }
        }
        N /= 2;
        bit_cnt *= 2;
    }
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
}