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

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> S[i][j];

    string big = "PRRRQLLLPRRQLLPRQ";
    map<int, pair<int, int>> mp;
    set<int> placed;
    rep(i, 5) {
        rep(j, 4) {
            mp[S[i][j]] = {i, 3 - j};
            placed.insert(S[i][j]);
        }
    }
    int x = 0, y = 1;
    set<int> rest;
    rep(i, N) rest.insert(i);
    set<int> ss;
    while (!placed.empty()) {
        int i = *placed.begin();
        auto [gx, gy] = mp[i];
        big += move(x, y, gx, gy);
        x = gx, y = gy;
        big += "P";
        if (gy == 0 && rest.count(gx)) {
            mp[S[gx][N - 1]] = {gx, 0};
            placed.insert(S[gx][N - 1]);
        }
        gx = i / N, gy = N - 1;
        big += move(x, y, gx, gy);
        x = gx, y = gy;
        big += "Q";
        placed.erase(i);
    }

    cout << big << endl;
    rep(i, 4) {
        cout << "PRRRQLLLPRRQLLPRQB" << endl;
    }
}
