#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    repp(i, 1, N) {
        rep(j, N - i) {
            if (S[j] == S[j + i]) {
                cout << j << endl;
                break;
            }
            if (j + i == N - 1) {
                cout << j + 1 << endl;
            }
        }
    }
}