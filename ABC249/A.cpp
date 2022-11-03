#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    int taka_dis = 0, aoki_dis = 0;
    rep(i, X) {
        if ((i % (A + C)) < A) {
            taka_dis += B;
        }
        if ((i % (D + F)) < D) {
            aoki_dis += E;
        }
    }
    if (taka_dis > aoki_dis) {
        cout << "Takahashi" << endl;
    } else if (taka_dis < aoki_dis) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}