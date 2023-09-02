#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);

    rep(i, N) {
        int x, y;
        cin >> x >> y;
        a[i] = x + y;
        b[i] = x - y;
    }

    sort(all(a));
    sort(all(b));

    cout << max(a[N - 1] - a[0], b[N - 1] - b[0]) << endl;
}