#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int cnt_pass = 0;
    rep(i, N) {
        if (S[i] == 'o' && cnt_pass < K) {
            cout << 'o';
            cnt_pass++;
        } else {
            cout << 'x';
        }
    }
    cout << endl;
}