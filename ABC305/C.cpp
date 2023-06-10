#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<pair<int, int>> cnt;
    rep(i, H) {
        int c = 0;
        rep(j, W) {
            if (S[i][j] == '#') {
                c++;
            }
        }
        if (c != 0) cnt.push_back(make_pair(c, i));
    }
    sort(all(cnt));

    vector<pair<int, int>> cnt2;
    rep(i, W) {
        int c = 0;
        rep(j, H) {
            if (S[j][i] == '#') {
                c++;
            }
        }
        if (c != 0) cnt2.push_back(make_pair(c, i));
    }
    sort(all(cnt2));

    cout << cnt[0].second + 1 << " " << cnt2[0].second + 1 << endl;
}