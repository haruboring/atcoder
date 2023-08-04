#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int H, W;
vector<string> S(0), cS(0);
bool check_8(int i, int j) {
    if (S[i][j] == '.') {
        return true;
    }
    if (
        (i == 0 || j == 0 || S[i - 1][j - 1] == '#') &&
        (i == 0 || S[i - 1][j] == '#') &&
        (i == 0 || j + 1 >= W || S[i - 1][j + 1] == '#') &&
        (j == 0 || S[i][j - 1] == '#') &&
        (j + 1 >= W || S[i][j + 1] == '#') &&
        (i + 1 >= H || j == 0 || S[i + 1][j - 1] == '#') &&
        (i + 1 >= H || S[i + 1][j] == '#') &&
        (i + 1 >= H || j + 1 >= W || S[i + 1][j + 1] == '#')) {
        return true;
    }
    return false;
}
void remove_8(int i, int j) {
    if (S[i][j] == '.') {
        cS[i][j] = '.';
    }
    if (
        (i != 0 && j != 0 && S[i - 1][j - 1] != '#') ||
        (i != 0 && S[i - 1][j] != '#') ||
        (i != 0 && j + 1 < W && S[i - 1][j + 1] != '#') ||
        (j != 0 && S[i][j - 1] != '#') ||
        (j + 1 < W && S[i][j + 1] != '#') ||
        (i + 1 < H && j != 0 && S[i + 1][j - 1] != '#') ||
        (i + 1 < H && S[i + 1][j] != '#') ||
        (i + 1 < H && j + 1 < W && S[i + 1][j + 1] != '#')) {
        cS[i][j] = '.';
    }
}
int main() {
    cin >> H >> W;
    rep(i, H) {
        string s;
        cin >> s;
        S.push_back(s);
        cS.push_back(s);
    }
    rep(i, H) {
        rep(j, W) {
            cout << i << " " << j << endl;
            if (check_8(i, j) == false) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    rep(i, H) {
        rep(j, W) {
            remove_8(i, j);
        }
    }
    cout << "possible" << endl;
    rep(i, H) {
        cout << cS[i] << endl;
    }
}