#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int st = A[0];
    cout << A[0] << " ";
    repp(i, 1, N) {
        if (abs(A[i] - st) == 1) {
            cout << A[i] << " ";
        }
        if (A[i] < st - 1) {
            for (int a = st - 1; a >= A[i]; a--) {
                cout << a << " ";
            }
        }
        if (A[i] > st + 1) {
            for (int a = st + 1; a <= A[i]; a++) {
                cout << a << " ";
            }
        }
        st = A[i];
    }
    cout << endl;
}