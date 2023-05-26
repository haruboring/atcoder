#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    rep(i, H) {
        rep(j, W) {
            if ((i < B && j < A) || (i >= B && j >= A)) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}