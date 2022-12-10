#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(200000 + 100);
    rep(i, N) {
        int L, R;
        cin >> L >> R;
        A[L]++;
        A[R]--;
    }
    int cnt = 0;
    bool b = false;
    rep(i, 200000 + 100) {
        cnt += A[i];
        if (b == false && cnt > 0) {
            cout << i << " ";
            b = true;
        } else if (cnt < 1 && b) {
            cout << i << endl;
            b = false;
        }
    }
}