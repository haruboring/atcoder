#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, L;
    cin >> N >> L;
    int K;
    cin >> K;
    vector<int> A(N + 2);
    A[0] = 0;
    rep(i, N) cin >> A[i + 1];
    A[N + 1] = L;

    multiset<int> st;
    rep(i, N + 1) {
        st.insert(A[i + 1] - A[i]);
    }

    rep(i, K) {
        int sm1 = *st.begin();
        st.erase(sm1);
        int sm2 = *st.rbegin();
        st.erase(sm2);

        st.insert(sm1 + sm2);
    }

    cout << *st.begin() << endl;
}