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
    vector<int> K(N);
    vector<vector<int>> A(N, vector<int>(0));
    rep(i, N) {
        cin >> K[i];
        rep(j, K[i]) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    // map<pair<int, int>, int> m;
    vector<unordered_map<int, int>> m(N);
    rep(i, N) {
        rep(j, K[i]) {
            m[i][A[i][j]]++;
        }
    }
    unordered_map<int, unordered_set<int>> sm;
    rep(i, N) {
        rep(j, K[i]) {
            sm[i].insert(A[i][j]);
        }
    }
    vector<int> size(N);
    rep(i, N) size[i] = sm[i].size();

    double ans = -1;
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            int cnt = 0;
            if (size[i] > size[j]) {
                for (auto x : sm[j]) {
                    cnt += m[i][x] * m[j][x];
                }
            } else {
                for (auto x : sm[i]) {
                    cnt += m[i][x] * m[j][x];
                }
            }
            ans = max(ans, (double)cnt / (K[i] * K[j]));
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}
