#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

void swap(int &a, int &b) {
    int a_copy = a;
    a = b;
    b = a_copy;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<vector<int>> aa(K, vector<int>(0));
    rep(i, N) {
        cin >> a[i];
        aa[i % K].push_back(a[i]);
    }
    sort(all(a));
    rep(i, K) {
        sort(all(aa[i]));
    }
    bool possible = true;
    vector<int> index(K);
    rep(i, N) {
        if (aa[i % K][index[i % K]] != a[i]) {
            possible = false;
        }
        index[i % K]++;
    }
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}