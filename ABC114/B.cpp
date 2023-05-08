#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int m = 10000;
    rep(i, S.size() - 2) {
        string ss = "";
        repp(j, i, i + 3) {
            ss += S[j];
        }
        m = min(m, abs(stoi(ss) - 753));
    }
    cout << m << endl;
}