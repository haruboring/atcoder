#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int a, b, C;
    cin >> a >> b >> C;

    bitset<60> bs(C);
    int pop_count = bs.count();

    debug(pop_count);

    int zero_count = 60 - pop_count;

    int same_pop_count = 0;
    while (pop_count + 2 * same_pop_count < a + b) {
        same_pop_count++;
    }

    if (pop_count + 2 * same_pop_count != a + b || same_pop_count > zero_count) {
        cout << -1 << endl;
        return 0;
    }

    int only_a_count = a - same_pop_count, only_b_count = b - same_pop_count;

    if (only_a_count < 0 || only_b_count < 0) {
        cout << -1 << endl;
        return 0;
    }

    string A = "", B = "";
    rep(i, 60) {
        if (bs[i]) {
            if (only_a_count > 0) {
                A += "1";
                B += "0";
                only_a_count--;
            } else {
                A += "0";
                B += "1";
            }
        } else {
            if (same_pop_count > 0) {
                A += "1";
                B += "1";
                same_pop_count--;
            } else {
                A += "0";
                B += "0";
            }
        }
    }

    debug(A);
    debug(B);

    int ansA = 0, ansB = 0;
    int tmp = 1LL;
    int cc = 0;
    int ccnt = 0;
    string sc = "";
    int acnt = 0, bcnt = 0;
    rep(i, 60) {
        if (A[i] == '1') {
            ansA += tmp;
            acnt++;
        }
        if (B[i] == '1') {
            ansB += tmp;
            bcnt++;
        }

        if (A[i] == '1' && B[i] == '0') {
            cc += tmp;
            sc += "1";
            ccnt++;
        } else if (A[i] == '0' && B[i] == '1') {
            cc += tmp;
            sc += "1";
            ccnt++;
        } else {
            sc += "0";
        }

        tmp *= 2LL;
    }

    debug(acnt);
    debug(bcnt);

    debug(cc);
    debug(sc);
    debug(ccnt);

    cout << ansA << " " << ansB << endl;
}