#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int K, S;
    cin >> K >> S;

    int cnt = 0;
    rep(i, K + 1) {
        rep(j, K + 1) {
            int k = S - i - j;
            if (0 <= k && k <= K) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}