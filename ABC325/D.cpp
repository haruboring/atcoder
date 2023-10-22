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
    vector<int> T(N), D(N);
    rep(i, N) cin >> T[i] >> D[i];

    map<int, vector<int>> in;
    rep(i, N) in[T[i]].push_back(i);

    set<int> in_times;
    rep(i, N) in_times.insert(T[i]);

    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    int time = 1;
    while (!(pq.empty() && in_times.empty())) {
        if (in_times.count(time)) {
            for (auto i : in[time]) pq.push(D[i] + time);
            in_times.erase(time);
        } else {
            time = *in_times.begin();
            continue;
        }

        while (!pq.empty()) {
            if(in_times.count(time)) break;

            int end = pq.top();
            pq.pop();
            if (end < time) {
                continue;
            }
            time++;
            ans++;
        }
    }

    cout << ans << endl;
}