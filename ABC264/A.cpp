#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int L, R;
    cin >> L >> R;
    string atc = "atcoder";

    cout << atc.substr(L - 1, R - L + 1) << endl;
}