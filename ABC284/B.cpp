#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        int N;
        cin >> N;
        int cnt = 0;
        rep(j, N) {
            int A;
            cin >> A;
            if (A % 2 == 1) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}