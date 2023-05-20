#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    sort(all(S));

    do {
        string ex_s = "";
        bool ans = true;
        for (string s : S) {
            if (ex_s != "") {
                int cnt = 0;
                rep(i, M) {
                    if (s[i] != ex_s[i]) {
                        cnt++;
                    }
                }
                if (cnt != 1) {
                    ans = false;
                    break;
                }
            }
            ex_s = s;
        }
        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(all(S)));
    cout << "No" << endl;
}