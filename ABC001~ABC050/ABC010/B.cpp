#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int sum = 0;
    set<int> s = {2, 4, 5, 6, 8};
    rep(i, n) {
        while (1) {
            if (s.count(a[i])) {
                a[i]--;
                sum++;
            } else {
                break;
            }
        }
    }
    cout << sum << endl;
}