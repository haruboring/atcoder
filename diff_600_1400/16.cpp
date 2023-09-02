#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> size(N + 1), cnt_p(N + 1);
    size[0] = 1;
    cnt_p[0] = 1;
    rep(i, N) {
        size[i + 1] = size[i] * 2 + 3;
        cnt_p[i + 1] = cnt_p[i] * 2 + 1;
    }

    ll eated = 0;
    while (X > 0) {
        if (N == 0) {
            eated++;
            break;
        }
        if (X == size[N - 1] + 2) {
            eated += cnt_p[N - 1] + 1;
            break;
        }
        if (X < size[N - 1] + 2) {
            X--;
            N--;
        }
        if (X > size[N - 1] + 2) {
            eated += cnt_p[N - 1] + 1;
            X -= size[N - 1] + 2;
            N--;
        }
    }

    cout << eated << endl;
}