#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int V;
    cin >> V;
    vector<int> use(3);
    rep(i, 3) {
        cin >> use[i];
    }
    int i = -1;
    while (V >= 0) {
        i++;
        V -= use[i % 3];
    }
    if (i%3 == 0) {
        cout << "F" << endl;
    } else if (i%3 == 1) {
        cout << "M" << endl;
    } else {
        cout << "T" << endl;
    }
}