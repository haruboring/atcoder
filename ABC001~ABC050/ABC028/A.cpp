#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    if (N < 60) {
        cout << "Bad" << endl;
    } else if (N < 90) {
        cout << "Good" << endl;
    } else if (N < 100) {
        cout << "Great" << endl;
    } else {
        cout << "Perfect" << endl;
    }
}