#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> abc(3);
    rep(i, 3) {
        cin >> abc[i];
    }
    sort(all(abc));
    cout << abc[1] << endl;
}