#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K;
    cin >> K;

    int ans = 0;
    repp(i, 1, pow(10, 4) + 1) {
        if (K % i != 0) continue;
        repp(j, i, sqrt(K / i) + 1) {
            int a = i * j;
            if (K % a == 0) {
                int b = K / a;
                if (b >= j) {
                    ans++;
                }
            }
        }
    }

    // Kの約数の個数は高々7000程度なので、約数を列挙して、二重ループで、50 10＾６だから、5 * 10^7で行ける

    cout << ans << endl;
}
