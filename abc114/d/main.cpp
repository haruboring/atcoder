#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N_;
    cin >> N_;

    map<int, int> m;
    for (int i = 2; i <= N_; i++) {
        int ci = i;
        for (int j = 2; j * j <= i; j++) {
            while (ci % j == 0) {
                m[j]++;
                ci /= j;
            }
        }
        if (ci > 1) m[ci]++;
    }

    int cnt = 0;
    vector<int> K;
    for (auto [k, c] : m) {
        cout << "(k, c) = " << k << ", " << c << endl;
        K.push_back(k);
    }
    int N = K.size();

    set<vector<int>> s;
    // 75
    for (int i = 0; i < N; i++) {
        int k1 = m[K[i]];
        if (m[k1] >= 74) s.insert(pow(K[i], 74));
    }
    // 25 * 3
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            vector<int> tmp = {i, j};
            sort(all(tmp));
            if (s.count(tmp)) continue;
            int k1 = m[K[i]], k2 = m[K[j]];
            if (k1 >= 24 && k2 >= 2) cnt++;
        }
    }

    // 15 * 5
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int k1 = m[K[i]], k2 = m[K[j]];
            if (k1 >= 14 && k2 >= 4) cnt++;
        }
    }

    // 5 * 5 * 3
    set<vector<int>> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                vector<int> tmp = {i, j};
                sort(all(tmp));
                if (i == j || j == k || k == i) continue;
                if (s.count(tmp)) continue;
                int k1 = m[K[i]], k2 = m[K[j]], k3 = m[K[k]];
                if (k1 >= 4 && k2 >= 4 && k3 >= 2) {
                    // cout << i << " " << j << " " << k << endl;
                    cout << k1 << " " << k2 << " " << k3 << endl;
                    cnt++;
                    s.insert(tmp);
                }
            }
        }
    }
    cout << cnt << endl;
}
