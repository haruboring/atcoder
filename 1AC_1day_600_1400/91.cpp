#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    S = "Z" + S + "Z";

    int ans = 0;
    int single = 0, extra = 0;
    for (int i = 1; i <= N; i++) {
        int comb = 0;
        while (S[i] == 'R' && S[i - (comb + 1)] == 'A' && S[i + (comb + 1)] == 'C') {
            comb++;
        }
        if (comb == 0) continue;
        if (comb == 1) {
            ans++;
            single++;
        } else {
            ans += 2;
            extra += (comb - 2);
        }
    }

    ans += min(single, extra);

    cout << ans << endl;
}