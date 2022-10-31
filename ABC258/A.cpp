#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int K;
    cin >> K;
    string MM = to_string(K % 60);
    cout << to_string(21 + K / 60) << ':' << setw(2) << setfill('0') << MM << endl;
}