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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<string> as(N);
    rep(i, N) {
        bitset<30> b(A[i]);
        as[i] = b.to_string();
        cout << as[i] << " ";
    }
    cout << endl;

    vector<int> zero(30), one(30);
    rep(i, N) {
        bool empty = true;
        rep(j, 30) {
            if (as[i][j] == '1') {
                if (!empty) one[j]++;
                empty = false;
            } else if (!empty) {
                zero[j]++;
            }
        }
    }
    reverse(all(zero));
    reverse(all(one));

    rep(i, 30) {
        cout << zero[i] << " ";
    }
    cout << endl;

    rep(i, 30) {
        cout << one[i] << " ";
    }
    cout << endl;

    int ans = 0;
    rep(i, 30) {
        if (one[i] > zero[i]) {
            ans += (1LL << i) * one[i];
        } else {
            ans += (1LL << i) * zero[i];
        }
    }

    cout << ans << endl;
}
