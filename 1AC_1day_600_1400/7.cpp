#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> R(N), H(N);
    rep(i, N) cin >> R[i] >> H[i];
    vector<int> sorted_R = R;
    sort(all(sorted_R));

    map<pair<int, int>, int> M;
    rep(i, N) {
        M[make_pair(R[i], H[i])]++;
    }

    rep(i, N) {
        int r = R[i], h = H[i];
        int ind = lower_bound(all(sorted_R), r) - sorted_R.begin();
        int w = ind + M[make_pair(r, h % 3 + 1)];
        int d = M[make_pair(r, h)] - 1;
        int l = N - 1 - w - d;
        cout << w << " " << l << " " << d << endl;
    }
}