#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, P;
    cin >> N >> P;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int failing_cnt = 0;
    rep(i, N) {
        if (a[i] < P) {
            failing_cnt++;
        }
    }
    cout << failing_cnt << endl;
}