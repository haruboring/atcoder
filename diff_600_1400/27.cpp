#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    string W;
    cin >> W;
    vector<string> c(9);
    rep(i, 9) cin >> c[i];

    vector<int> dxy;
    if (W == "R") dxy = {1, 0};
    if (W == "L") dxy = {-1, 0};
    if (W == "U") dxy = {0, -1};
    if (W == "D") dxy = {0, 1};
    if (W == "RU") dxy = {1, -1};
    if (W == "RD") dxy = {1, 1};
    if (W == "LU") dxy = {-1, -1};
    if (W == "LD") dxy = {-1, 1};

    string ans = "";
    rep(i, 4) {
        int nx = x + i * dxy[0];
        int ny = y + i * dxy[1];
        if (nx > 8) nx = 8 - (nx - 8);
        if (ny > 8) ny = 8 - (ny - 8);
        ans += c[abs(ny)][abs(nx)];
    }

    cout << ans << endl;
}