#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<vector<ll>> G(1e5, vector<ll>(0));
    rep(i, 1e5) {
        string s = to_string(i);
        ll sum = 0;
        rep(j, s.size()) {
            sum += s.at(j) - '0';
            sum %= 100000;
        }
        sum += i;
        sum %= 100000;
        G[i].push_back(sum);
    }

    vector<ll> dist(1e5, -1);
    map<ll, ll> mp;
    queue<ll> q;
    q.push(N);
    dist[N] = 0;
    mp[0] = N;
    ll loop_cnt = 0;
    ll loop_start_id = 0;
    ll max_no_loop_cnt = 0;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll nv : G[v]) {
            if (dist[nv] != -1) {
                loop_cnt = dist[v] - dist[nv] + 1;
                loop_start_id = dist[nv];
                break;
            }
            dist[nv] = dist[v] + 1;
            q.push(nv);
            mp[dist[nv]] = nv;
            max_no_loop_cnt++;
        }
    }

    if (K <= max_no_loop_cnt) {
        cout << mp[K] << endl;
    } else {
        K -= loop_start_id;
        K %= loop_cnt;
        cout << mp[loop_start_id + K] << endl;
    }
}
