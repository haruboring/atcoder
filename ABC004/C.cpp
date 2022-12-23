#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int slide = N / 5;
    vector<int> card(6);
    rep(i, 6) {
        card[i] = (i + slide) % 6 + 1;
    }
    rep(i, N % 5) {
        int buf = card[i];
        card[i] = card[i + 1];
        card[i + 1] = buf;
    }
    rep(i, 6) {
        cout << card[i];
    }
    cout << endl;
}