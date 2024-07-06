#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

string move(int x, int y, int gx, int gy) {
    string res = "";
    while (x != gx) {
        if (x < gx) {
            res += "D";
            x++;
        } else {
            res += "U";
            x--;
        }
    }
    while (y != gy) {
        if (y < gy) {
            res += "R";
            y++;
        } else {
            res += "L";
            y--;
        }
    }
    return res;
}

int distance(int x, int y, int gx, int gy) {
    return abs(x - gx) + abs(y - gy);
}

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> S[i][j];

    string big = "PRRRQLLLPRRQLLPRQ";
    map<int, pair<int, int>> mp;
    map<pair<int, int>, int> rmp;
    set<int> placed;
    set<int> input_zone;
    rep(i, 5) {
        rep(j, 4) {
            mp[S[i][j]] = {i, 3 - j};
            rmp[{i, 3 - j}] = S[i][j];
            placed.insert(S[i][j]);
            if (3 - j == 0) {
                input_zone.insert(S[i][j]);
            }
        }
    }
    int x = 0, y = 1;
    set<pair<int, int>> rest;
    rep(i, N) rest.insert({S[i][N - 1], i});
    int ex = 0, ey = 0;
    int risou_i = 0;

    vector<set<int>> ss(N);
    rep(i, N) rep(j, N) ss[i].insert(i * N + j);
    while (!placed.empty()) {
        int i = -1;
        rep(s, N) {
            if (ss[s].size() != 0 && placed.count(*ss[s].begin())) {
                i = *ss[s].begin();
                break;
            }
        }
        if (i == -1) {
            i = *placed.begin();
        }

        auto [ex, ey] = mp[i];
        big += move(x, y, ex, ey);
        x = ex, y = ey;
        big += "P";

        int gx = i / N, gy = N - 1;
        big += move(x, y, gx, gy);
        x = gx, y = gy;
        big += "Q";
        placed.erase(i);
        rep(s, N) rep(k, N) if (ss[s].count(i)) ss[s].erase(i);

        if (ey == 0 && rest.count({S[ex][N - 1], ex})) {
            mp[S[ex][N - 1]] = {ex, 0};
            rmp[{ex, 0}] = S[ex][N - 1];
            placed.insert(S[ex][N - 1]);
            input_zone.insert(S[ex][N - 1]);
            rest.erase({S[ex][N - 1], ex});
        } else if (!rest.empty()) {
            auto [_, next] = *rest.begin();
            bool cn = false;
            rep(s, N) {
                if (placed.count(*ss[s].begin())) {
                    cn = true;
                    break;
                }
            }
            if (cn) continue;
            int fx = next, fy = 0;
            int j = rmp[{next, 0}];
            big += move(x, y, fx, fy);
            x = fx, y = fy;
            big += "P";
            big += move(x, y, ex, ey);
            big += "Q";
            x = ex, y = ey;
            mp[j] = {ex, ey};
            rmp[{ex, ey}] = j;
            placed.insert(j);

            mp[S[fx][N - 1]] = {fx, 0};
            rmp[{fx, 0}] = S[fx][N - 1];
            placed.insert(S[fx][N - 1]);

            rest.erase({_, next});
        }
    }

    cout << big << endl;
    rep(i, 4) {
        cout << "PRRRQLLLPRRQLLPRQB" << endl;
    }
}
// seed18 : 700 -> 492
// seed23 : 414 -> 306