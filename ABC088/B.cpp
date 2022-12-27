#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
    }
    int al = 0, bo = 0;
    sort(all(a));
    reverse(all(a));
    rep(i, N) {
        if (i % 2 == 0) {
            al += a[i];
        } else {
            bo += a[i];
        }
    }
    cout << al - bo << endl;
}