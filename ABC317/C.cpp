#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M), C(M);
    vector<vector<pair<ll, ll>>> G(N);
    rep(i, M) cin >> A.at(i) >> B.at(i) >> C.at(i);
    rep(i, M) A.at(i)--, B.at(i)--;

    map<pair<ll, ll>, ll> mp;
    rep(i, M) {
        mp[make_pair(A[i], B[i])] = C[i];
        mp[make_pair(B[i], A[i])] = C[i];
    }

    vector<int> step(N);
    rep(i, N) step[i] = i;

    int ans = 0;

    do {
        int tmp = 0;
        rep(i, N - 1) {
            if (mp[make_pair(step[i], step[i + 1])] == 0) {
                break;
            }
            tmp += mp[make_pair(step[i], step[i + 1])];
        }
        ans = max(ans, tmp);
    } while (next_permutation(all(step)));

    cout << ans << endl;
}