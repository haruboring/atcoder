#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> I(3);
    rep(i, 3) cin >> I[i];
    sort(all(I));
    cout << I[1] + I[2] << endl;
}