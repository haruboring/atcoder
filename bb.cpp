// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    string T;
    cin >> T;

    int px = X - 1, py = Y - 1;
    int cnt = 0;

    set<pair<int, int>> st;

    rep(i, T.size()) {
        int nx = px, ny = py;
        if (S[nx][ny] == '@') {
            st.insert({nx, ny});
        }
        if (T[i] == 'U' && px > 0 && S[px - 1][py] != '#') nx--;
        if (T[i] == 'D' && px < H - 1 && S[px + 1][py] != '#') nx++;
        if (T[i] == 'L' && py > 0 && S[px][py - 1] != '#') ny--;
        if (T[i] == 'R' && py < W - 1 && S[px][py + 1] != '#') ny++;
        if (S[nx][ny] == '@') {
            st.insert({nx, ny});
        }

        px = nx, py = ny;
    }

    cout << px + 1 << " " << py + 1 << " " << st.size() << endl;
}