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
    vector<pair<int, int>> SC(N);
    rep(i, N) {
        cin >> SC[i].first >> SC[i].second;
    }

    sort(all(SC));

    int ans = 0;

    map<int, int> res;

    for (auto [size, num] : SC) {
        if (res.count(size)) num += res[size];
        res[size] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(size, num));

        while (!pq.empty()) {
            auto [size, num] = pq.top();
            if (res.count(size)) num += res[size];
            res[size] = 0;

            pq.pop();

            if (num >= 2) {
                pq.push(make_pair(2 * size, num / 2));
            }

            if (!res.count(size)) res[size] = 0;

            res[size] += num % 2;
        }
    }

    for (auto [size, num] : res) {
        ans += num;
    }

    cout << ans << endl;
}