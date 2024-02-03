#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<char>> S(H, vector<char>(W, '.'));

    int pos_i = 0, pos_j = 0;
    vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int angle = 0;
    rep(_, N) {
        if (S[pos_i % H][pos_j] == '.') {
            S[pos_i][pos_j] = '#';
            angle++;
            pos_i += moves[angle % 4][0];
            pos_j += moves[angle % 4][1];
            pos_i = (pos_i + H) % H;
            pos_j = (pos_j + W) % W;
        } else {
            S[pos_i][pos_j] = '.';
            angle--;
            pos_i += moves[angle % 4][0];
            pos_j += moves[angle % 4][1];
            pos_i = (pos_i + H) % H;
            pos_j = (pos_j + W) % W;
        }
    }

    rep(i, H) {
        rep(j, W) {
            cout << S[i][j];
        }
        cout << endl;
    }
}
