#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    stringstream s;
    s << hex << N;
    string ss = s.str();
    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);
    if (ss.size() == 1) {
        cout << 0 << ss << endl;
    } else {
        cout << ss << endl;
    }
}