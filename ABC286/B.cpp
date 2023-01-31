#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string ans = "";
    bool pre_n = false;
    rep(i, N) {
        if (S[i] == 'n') {
            pre_n = true;
            ans += S[i];
        } else {
            if (pre_n && S[i] == 'a') {
                ans += "ya";
            } else {
                ans += S[i];
            }
            pre_n = false;
        }
    }
    cout << ans << endl;
}