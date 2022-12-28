#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1, 1);
    int pos = 2;
    while (pos * pos <= N) {
        if (A[pos] == 1) {
            cout << pos << endl;
        }
        for (int i = 2; i * pos <= N; i++) {
            A[i * pos]--;
        }
        pos++;
    }
    repp(i, pos, N + 1) {
        if (A[i] == 1) {
            cout << i << endl;
        }
    }
}