#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string N;
    cin >> N;
    int ans = 0;
    rep(i, N.size()) {
        ans += int(N[N.size() - 1 - i] - '0') * pow(2, i);
    }
    cout << ans << endl;
}