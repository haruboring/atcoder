#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int T, N;
    cin >> T >> N;
    vector<int> L(N), R(N), em(T);
    rep(i, N) {
        cin >> L[i] >> R[i];
        em[L[i]]++;
        em[R[i]]--;
    }
    int number_of_employee = 0;
    rep(i, T) {
        number_of_employee += em[i];
        cout << number_of_employee << endl;
    }
}