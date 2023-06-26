#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            string concated = S[i] + S[j];
            string r_concated = concated;
            reverse(all(r_concated));
            if (concated == r_concated) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}