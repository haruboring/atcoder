#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll ans = 1;
ll BASE = 1000000000;
map<ll, vector<ll>> AB;
vector<bool> b(BASE + 1);
void f(int kai) {
    b[kai] = true;
    int cnt = 0;
    rep(i, AB[kai].size()) {
        if (b[AB[kai][i]] == false) {
            f(AB[kai][i]);
            ans = max(ans, AB[kai][i]);
            cnt++;
        }
    }
    if (cnt == 0) {
        return;
    }
}

int main() {
    int N;
    cin >> N;
    rep(i, N) {
        int A, B;
        cin >> A >> B;
        AB[A].push_back(B);
        AB[B].push_back(A);
    }
    f(1);
    cout << ans << endl;
}