#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> copyA = A;
    sort(all(copyA));

    vector<ll> ans(N);
    ll sum = 0;
    ll st = 0;
    rep(i, N) {
        if (sum + ((copyA[i] - st) * (N - i)) >= K) {
            ll rest_apples = K - sum;
            ll boxes_which_have_apples = N - i;

            rep(i, N) {
                ans[i] = max(0LL, A[i] - st - (rest_apples / boxes_which_have_apples));
            }
            rest_apples %= boxes_which_have_apples;
            rep(i, N) {
                if (rest_apples == 0) break;
                if (ans[i] > 0) {
                    ans[i]--;
                    rest_apples--;
                }
            }

            rep(i, N) {
                cout << ans[i] << " ";
            }
            cout << endl;
            return 0;
        }

        sum += (copyA[i] - st) * (N - i);
        st = copyA[i];
    }
}