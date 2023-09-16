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
    string atc = "atcoder";
    int index = 0, cnt = 0;
    while (1) {
        if (index >= 7) {
            break;
        }
        rep(i, 7) {
            if (S[i] == atc[index]) {
                rep(j, i - index) {
                    swap(S[i - j], S[i - j - 1]);
                    cnt++;
                }
                index++;
            }
        }
    }
    cout << cnt << endl;
}