#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    rep(i, N * A) {
        rep(j, N * B) {
            if ((j / B) % 2 == (i / A) % 2) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
}