#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W, R, C;
    cin >> H >> W >> R >> C;
    int ans = 4;
    if (R == 1) {
        ans--;
    }
    if (R == H) {
        ans--;
    }
    if (C == 1) {
        ans--;
    }
    if (C == W) {
        ans--;
    }
    cout << ans << endl;
}