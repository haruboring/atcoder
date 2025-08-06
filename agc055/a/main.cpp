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
    string S;
    cin >> S;

    vector<vector<int>> C(3, vector<int>(3));
    rep(i, 3 * N) C[S[i] - 'A'][i / N]++;
    vector<int> ass(3 * N, -1);

    rep(i, 6) {
        int mk = 0;
        string ms = "ABC";
        for (string s : {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"}) {
            int k = 1e9;
            rep(j, 3) k = min(k, C[s[j] - 'A'][j]);
            if (k > mk) {
                mk = k;
                ms = s;
            }
        }

        C[ms[0] - 'A'][0] -= mk;
        C[ms[1] - 'A'][1] -= mk;
        C[ms[2] - 'A'][2] -= mk;
        debug("koko");
        map<int, int> m;
        rep(j, 3 * N) {
            if (ass[j] != -1) continue;
            if (m[j / N] < mk && S[j] == ms[j / N]) {
                ass[j] = i + 1;
                m[j / N]++;
            }
        }
    }

    rep(i, 3 * N) cout << ass[i];
    cout << endl;
}
