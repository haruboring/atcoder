#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<string> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vector<int> move_hor = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> move_ver = {1, 0, -1, 1, -1, 1, 0, -1};
    int max_number = 0;
    rep(i, N) {
        rep(j, N) {
            rep(k, 8) {
                int keta = 1;
                int loaded_number = 0;
                rep(l, N) {
                    loaded_number += (keta * (A[(N + i + move_ver[k] * l) % N][(N + j + move_hor[k] * l) % N] - '0'));
                    keta *= 10;
                }
                max_number = max(max_number, loaded_number);
            }
        }
    }
    cout << max_number << endl;
}