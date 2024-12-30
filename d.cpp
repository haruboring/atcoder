// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, Sx, Sy;
    cin >> N >> M >> Sx >> Sy;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    vector<char> D(M);
    vector<int> C(M);
    rep(i, M) cin >> D[i] >> C[i];

    map<int, set<int>> x_by_y, y_by_x;
    rep(i, N) {
        x_by_y[Y[i]].insert(X[i]);
        y_by_x[X[i]].insert(Y[i]);
        // debug(X[i]);
    }

    int x = Sx, y = Sy;
    int ans = 0;
    rep(i, M) {
        int nx = x, ny = y;
        if (D[i] == 'U') {
            ny += C[i];
            auto b = y_by_x[x].lower_bound(y);
            auto e = y_by_x[x].upper_bound(ny);

            set<pair<int, int>> s;
            for (auto it = b; it != e; it++) {
                ans++;
                s.insert({x, *it});
            }

            for (auto [x, y] : s) {
                y_by_x[x].erase(y);
                x_by_y[y].erase(x);
            }

            y = ny;
        }
        if (D[i] == 'D') {
            ny -= C[i];
            auto b = y_by_x[x].lower_bound(ny);
            auto e = y_by_x[x].upper_bound(y);

            set<pair<int, int>> s;
            for (auto it = b; it != e; it++) {
                ans++;
                s.insert({x, *it});
            }

            for (auto [x, y] : s) {
                y_by_x[x].erase(y);
                x_by_y[y].erase(x);
            }

            y = ny;
        }
        if (D[i] == 'L') {
            nx -= C[i];
            auto b = x_by_y[y].lower_bound(nx);
            auto e = x_by_y[y].upper_bound(x);

            set<pair<int, int>> s;
            for (auto it = b; it != e; it++) {
                ans++;
                s.insert({*it, y});
            }

            for (auto [x, y] : s) {
                x_by_y[y].erase(x);
                y_by_x[x].erase(y);
            }

            x = nx;
        }
        if (D[i] == 'R') {
            nx += C[i];
            auto b = x_by_y[y].lower_bound(x);
            auto e = x_by_y[y].upper_bound(nx);

            set<pair<int, int>> s;
            for (auto it = b; it != e; it++) {
                ans++;
                s.insert({*it, y});
            }

            for (auto [x, y] : s) {
                x_by_y[y].erase(x);
                y_by_x[x].erase(y);
            }

            x = nx;
        }
    }

    cout << x << " " << y << " " << ans << endl;
}