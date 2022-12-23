#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, D;
    cin >> N >> D;
    vector<pair<ll, ll>> RL(N);
    rep(i, N) {
        ll L, R;
        cin >> L >> R;
        RL[i] = make_pair(R, L);
    }
    sort(all(RL));
    ll panch_index = 0, broken_index = 0, cnt = 1;
    while (broken_index < N) {
        if (RL[broken_index].second < RL[panch_index].first + D) {
            broken_index++;
        } else {
            panch_index = broken_index;
            cnt++;
        }
    }
    cout << cnt << endl;
}