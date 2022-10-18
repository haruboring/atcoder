#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;
    set<int> answerd_A, answerd_B;
    int ans=0;
    while (A > 0) {
        if (A - 4 >= 0) {
            answerd_A.insert(4);
            A -= 4;
        } else if (A - 2 >= 0) {
            answerd_A.insert(2);
            A -= 2;
        } else {
            answerd_A.insert(1);
            A--;
        }
    }
    while (B > 0) {
        if (B - 4 >= 0) {
            answerd_B.insert(4);
            B -= 4;
        } else if (B - 2 >= 0) {
            answerd_B.insert(2);
            B -= 2;
        } else {
            answerd_B.insert(1);
            B--;
        }
    }
    if (answerd_A.count(1) || answerd_B.count(1)) {
        ans++;
    }
    if (answerd_A.count(2) || answerd_B.count(2)) {
        ans+=2;
    }
    if (answerd_A.count(4) || answerd_B.count(4)) {
        ans+=4;
    }
    cout << ans << endl;
}