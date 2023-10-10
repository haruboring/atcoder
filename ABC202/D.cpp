#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// COMinit
int comb(int a, int b) {
    int ans = 1;
    rep(i, b) {
        ans = (ans * (a - i)) / (i + 1);
    }
    return ans;
}

signed main() {
    int A, B, K;
    cin >> A >> B >> K;

    K--;

    string s = "";
    int set_a = 0;
    rep(i, A + B) {
        int cm = comb(A + B - i - 1, A - set_a - 1);
        if (set_a == A) {
            s += 'b';
        } else if (cm <= K) {
            K -= cm;
            s += 'b';
        } else {
            s += 'a';
            set_a++;
        }
    }

    cout << s << endl;
}