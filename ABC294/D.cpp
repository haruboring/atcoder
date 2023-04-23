#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    set<int> call, go, uncall;
    rep(i, N) {
        uncall.insert(i + 1);
    }
    rep(i, Q) {
        int flag;
        cin >> flag;
        if (flag == 1) {
            int calling_number = *begin(uncall);
            uncall.erase(calling_number);
            call.insert(calling_number);
        } else if (flag == 2) {
            int x;
            cin >> x;
            call.erase(x);
            go.insert(x);
        } else {
            cout << int(*begin(call)) << endl;
        }
    }
}