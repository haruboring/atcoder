#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

bool is_not_set_koma(vector<int> A, int position) {
    int N = A.size();
    bool b = true;
    rep(i, N) {
        if (A[i] == position + 1) {
            b = false;
        }
    }
    return b;
}

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(K), L(Q);
    rep(i, K) {
        cin >> A[i];
    }
    rep(i, Q) {
        cin >> L[i];
    }
    rep(i, Q) {
        if (A[L[i] - 1] == N) {
            continue;
        } else {
            if (is_not_set_koma(A, A[L[i] - 1])) {
                A[L[i] - 1]++;
            }
        }
    }
    rep(i, K) {
        cout << A[i] << " ";
    }
    cout << endl;
}