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
    string check = "WWBWBWW";
    int pos = -1;
    rep(i, S.size() - 7) {
        bool b = true;
        rep(j, check.size()) {
            if (S[i + j] != check[j]) {
                b = false;
                break;
            }
        }
        if (b) {
            pos = i;
            break;
        }
    }
    string ans = "";
    switch (pos) {
        case 0:
            ans = "Si";
            break;
        case 11:
            ans = "Do";
            break;
        case 9:
            ans = "Re";
            break;
        case 7:
            ans = "Mi";
            break;
        case 6:
            ans = "Fa";
            break;
        case 4:
            ans = "So";
            break;
        case 2:
            ans = "La";
            break;
    }
    cout << ans << endl;
}