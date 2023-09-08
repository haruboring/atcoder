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
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    vector<int> cP = P;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[P[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (P[i] != i + 1) cnt++;
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<pair<char, int>> ans;

    int l = 0, r = 0;
    rep(i, N) {
        if (P[i] % 2 != (i + 1) % 2) {
            if (P[i] % 2 == 0) {
                for (int j = i - 2; j >= l * 2; j -= 2) {
                    swap(P[j], P[j + 2]);
                    ans.push_back({'B', j + 1});
                }
                l++;
            } else {
                for (int j = i - 2; j >= r * 2 + 1; j -= 2) {
                    swap(P[j], P[j + 2]);
                    ans.push_back({'B', j + 1});
                }
                r++;
            }
        }
    }

    for (int i = 0; i < l; i++) {
        swap(P[i * 2], P[i * 2 + 1]);
        ans.push_back({'A', i * 2 + 1});
    }

    for (int p = 1; p <= N; p++) {
        for (int i = 0; i < N; i++) {
            if (P[i] == p) {
                for (int j = i - 2; j >= p - 1; j -= 2) {
                    swap(P[j], P[j + 2]);
                    ans.push_back({'B', j + 1});
                }
                break;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto [c, i] : ans) {
        cout << c << " " << i << endl;
    }

    rep(i, N) debug(P[i]);
}