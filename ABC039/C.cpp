#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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