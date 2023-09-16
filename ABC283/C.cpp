#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;
    int cnt = 0;
    while (S.size() > 0) {
        if (S[0] != '0') {
            cnt++;
            S.erase(0, 1);
        } else if (S[0] == '0') {
            if (S.size() != 1 && S[1] == '0') {
                cnt++;
                S.erase(0, 2);
            } else {
                cnt++;
                S.erase(0, 1);
            }
        }
    }
    cout << cnt << endl;
}