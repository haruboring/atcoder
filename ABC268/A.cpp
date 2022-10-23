#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    set<int> S;
    S.insert(A);
    S.insert(B);
    S.insert(C);
    S.insert(D);
    S.insert(E);
    cout << S.size() << endl;
}