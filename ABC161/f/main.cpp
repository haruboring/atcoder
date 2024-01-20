#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    set<int> st;
    for (int j = 1; j * j <= (N - 1); j++) {
        if ((N - 1) % j != 0) continue;
        st.insert(j);
        st.insert((N - 1) / j);
    }
    int cN = N;
    for (int i = 2; i * i <= cN; i++) {
        int cnt = 0;
        while (N % i == 0) {
            N /= i;
            cnt++;
        }

        rep(j, cnt) N *= i;

        int tmp = 1;
        rep(j, cnt) {
            tmp *= i;
            if ((cN / tmp - 1) % i == 0) st.insert(i);
        }
    }

    st.insert(cN);
    if (st.count(1)) st.erase(1);

    cout << st.size() << endl;
}
