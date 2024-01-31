#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    if (M == K) {
        int ans = 0;
        rep(i, M) ans += A[i];
        cout << ans << " ";
        rep(i, N - M) {
            ans -= A[i];
            ans += A[M + i];
            cout << ans << " ";
        }
        cout << endl;
        return 0;
    }

    multiset<int> top_K, not_top_K;
    int top_K_sum = 0;
    vector<int> tmp(M);
    rep(i, M) tmp[i] = A[i];
    sort(all(tmp));
    rep(i, K) {
        top_K.insert(tmp[i]);
        top_K_sum += tmp[i];
    }
    repp(i, K, M) not_top_K.insert(tmp[i]);

    cout << top_K_sum << " ";
    rep(i, N - M) {
        int new_A = A[M + i];
        int erase_A = A[i];
        if (erase_A <= *top_K.rbegin()) {
            top_K_sum -= erase_A;
            top_K.erase(top_K.find(erase_A));
            top_K.insert(*not_top_K.begin());
            top_K_sum += *not_top_K.begin();
            not_top_K.erase(not_top_K.begin());
        } else {
            not_top_K.erase(not_top_K.find(erase_A));
        }
        if (new_A < *top_K.rbegin()) {
            top_K_sum -= *top_K.rbegin();
            not_top_K.insert(*top_K.rbegin());
            top_K.erase(top_K.find(*top_K.rbegin()));
            top_K.insert(new_A);
            top_K_sum += new_A;
        } else {
            not_top_K.insert(new_A);
        }

        cout << top_K_sum << " ";
    }
    cout << endl;
}
