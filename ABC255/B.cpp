#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i, K) {
        cin >> A[i];
    }
    vector<int> X(N), Y(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
    }
    vector<double> distance(N);
    rep(i, N) {
        distance[i] = 300000;
    }
    rep(i, N) {
        rep(j, K) {
            if (i == A[j] - 1) {
                break;
            }
        }
        rep(j, K) {
            distance[i] = min(distance[i], sqrt(pow(X[i] - X[A[j] - 1], 2) + pow(Y[i] - Y[A[j] - 1], 2)));
        }
    }
    sort(all(distance));
    reverse(all(distance));
    rep(i, N) {
        if (distance[i] != 300000) {
            cout << fixed << setprecision(20) << distance[i] << endl;
            break;
        }
    }
}