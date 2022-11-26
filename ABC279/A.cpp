#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int cnt = 0;
    rep(i, S.size()) {
        if (S[i] == 'v') {
            cnt++;
        } else {
            cnt += 2;
        }
    }
    cout << cnt << endl;
}