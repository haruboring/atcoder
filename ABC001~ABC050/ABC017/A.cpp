#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int s1, e1, s2, e2, s3, e3;
    cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;
    int ans = s1 * e1 + s2 * e2 + s3 * e3;
    ans /= 10;
    cout << ans << endl;
}