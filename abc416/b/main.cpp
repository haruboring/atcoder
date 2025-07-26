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

    string T = "";
    int N = S.size();
    int bef = -1;
    bool hav = false;
    int cnt = 0;
    rep(i, N) {
        if (S[i] == '#') {
            T += "#";
            if (bef != -1) {
                hav = true;
            }
            cnt++;
        } else {
            T += ".";
            if (bef == -1) {
                bef = i;
            }
            if (bef != -1 && hav) {
                T[bef] = 'o';
                T[i] = 'o';
                bef = i;
                hav = false;
            }
        }
    }

    if (cnt == 0) {
        T[0] = 'o';
    }

    cout << T << endl;
}
