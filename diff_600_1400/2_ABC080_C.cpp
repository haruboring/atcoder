#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    rep(i, N) {
        rep(j, 10) {
            cin >> F[i][j];
        }
    }
    vector<vector<int>> P(N, vector<int>(11));
    rep(i, N) {
        rep(j, 11) {
            cin >> P[i][j];
        }
    }
    int ans = -1e9;
    rep(i, (1 << 10)) {
        if (i == 0) continue;
        bitset<10> b(i);
        int earn = 0;
        rep(j, N) {
            int cnt = 0;
            rep(k, 10) {
                if (F[j][k] == 1 && b.test(k) == 1) {
                    cnt++;
                }
            }
            earn += P[j][cnt];
        }
        ans = max(ans, earn);
    }
    cout << ans << endl;
}