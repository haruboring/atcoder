#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int P;
    cin >> P;
    int ans = 0;
    int tmp = 1;
    int k = 1;
    while (P > 0) {
        if (P <= tmp) {
            debug(tmp);
            if (P != tmp) {
                tmp /= (k - 1);
            }
            debug(tmp);
            P -= tmp;
            ans++;
            tmp = 1;
            k = 1;
        } else {
            tmp *= k;
            k++;
        }
    }

    cout << ans << endl;
}