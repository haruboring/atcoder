#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<int> B(M), C(M);
    vector<vector<int>> I(M, vector<int>(0));
    rep(i, M) {
        cin >> B[i] >> C[i];
        rep(j, C[i]) {
            int tmp;
            cin >> tmp;
            I[i].push_back(tmp - 1);
        }
    }

    ll ans = -1;

    rep(i, (1 << N)) {
        bitset<16> s(i);
        ll power = 0;
        set<ll> mem;
        rep(j, N) {
            if (s.test(j)) {
                power += A[j];
                mem.insert(j);
            }
        }
        if (mem.size() != 9) {
            continue;
        }
        rep(j, M) {
            ll cnt = 0;
            rep(k, C[j]) {
                if (mem.count(I[j][k])) {
                    cnt++;
                }
            }
            if (cnt >= 3) {
                power += B[j];
            }
        }
        ans = max(ans, power);
    }

    cout << ans << endl;
}