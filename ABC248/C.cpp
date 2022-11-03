#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int N, M, K;
ll ans = 1;
ll BASE = 998244353;

ll a(int nokori, int nokori_retu) {
    if (nokori_retu <= 0) {
        return ans;
    }
    ll memo = 0;
    repp(i, 1, min(M, nokori - (nokori_retu - 1)) + 1) {
        cout << nokori_retu << endl;
        memo += a(nokori - i, nokori_retu - 1);
    }
    ans += (memo % BASE);
    ans %= BASE;
    return ans;
}

int main() {
    cin >> N >> M >> K;
    cout << a(K, N) << endl;
}