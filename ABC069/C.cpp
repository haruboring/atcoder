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
    int cnt = 0, t = 0;
    rep(i, N) {
        if (a[i] % 4 == 0) {
            cnt += 2;
        } else if (a[i] % 2 == 0) {
            t++;
        }
    }
    if (t != 0) {
        t--;
    }
    if (cnt + t >= N - 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}