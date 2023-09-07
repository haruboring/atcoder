#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> v(1000002, 0);
    int n;
    cin >> n;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b + 1]--;
    }
    int ans = v[0];
    repp(i, 1, 1000002) {
        v[i] += v[i - 1];
        ans = max(ans, v[i]);
    }
    cout << ans << endl;
}