#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) {
        cin >> H[i];
    }
    int ans = 1;
    int high = H[0];
    repp(i, 1, N) {
        if (high < H[i]) {
            ans = i + 1;
            high = H[i];
        }
    }
    cout << ans << endl;
}