#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, C;
    cin >> N >> C;
    map<ll, ll> cost_up_down_per_day;
    rep(i, N) {
        ll a, b, c;
        cin >> a >> b >> c;
        cost_up_down_per_day[a] += c;
        cost_up_down_per_day[b + 1] -= c;
    }
    ll day_cost = 0;
    ll ans = 0;
    ll paid_day = -1;
    for (auto cost : cost_up_down_per_day) {
        if (paid_day == -1) {
            paid_day = cost.first - 1;
        }
        if (day_cost > C) {
            ans += C * (cost.first - 1 - paid_day);
        } else {
            ans += day_cost * (cost.first - 1 - paid_day);
        }
        day_cost += cost.second;
        paid_day = cost.first - 1;
    }
    cout << ans << endl;
}