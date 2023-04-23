#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll l = 0, r = N - 1;
    int mid = (l + r) / 2;
    while (r - l > 1) {
        cout << "? " << mid + 1 << endl;
        cout << flush;
        int inp;
        cin >> inp;
        if (inp == 0) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    cout << "! " << l + 1 << endl;
}
