#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<string> x(N);
    rep(i, N) cin >> x[i];

    int ans = 0;
    rep(i, 9) {
        rep(j, N) {
            if (x[N - j - 1][i] == 'x')
                ans++;
            else if (x[N - j - 1][i] == 'o' && (j == 0 || x[N - j][i] != 'o'))
                ans++;
        }
    }

    cout << ans << endl;
}