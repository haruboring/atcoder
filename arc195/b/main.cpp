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
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int z_min = max(*max_element(all(A)), *max_element(all(B)));
    map<int, int> a, b;
    rep(i, N) {
        a[A[i]]++;
        b[B[i]]++;
    }

    vector<pair<int, int>> P;
    for (auto [ax, av] : a) {
        for (auto [bx, bv] : b) {
            if (ax + bx >= z_min) {
                P.push_back({ax + bx, min(av, bv)});
            }
        }
    }
    if (P.size() == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    sort(all(P));

    int t = P[0].second;
    repp(i, 1, P.size()) {
        if (P[i].first == P[i - 1].first) {
            t += P[i].second;
        } else {
            if (N - t <= a[-1] + b[-1]) {
                cout << "Yes" << endl;
                return 0;
            }

            t = P[i].second;
        }
    }

    if (N - t <= a[-1] + b[-1]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
