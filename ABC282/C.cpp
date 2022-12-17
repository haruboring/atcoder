#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int c = 0;
    rep(i, N) {
        if (S[i] == '"') {
            c++;
        }
        if (S[i] == ',') {
            if (c % 2 == 0) {
                cout << '.';
            } else {
                cout << ",";
            }
        } else {
            cout << S[i];
        }
    }
    cout << endl;
}