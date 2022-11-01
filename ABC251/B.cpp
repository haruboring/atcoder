#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    set<int> S;
    sort(all(A));
    rep(i, N) {
        if (A[i] <= W) {
            S.insert(A[i]);
        }
    }
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            if (A[i] + A[j] <= W) {
                S.insert(A[i] + A[j]);
            }
        }
    }
    rep(i, N - 2) {
        if (A[i] > W) {
            break;
        }
        repp(j, i + 1, N - 1) {
            if (A[i] + A[j] > W) {
                break;
            }
            repp(k, j + 1, N) {
                if (A[i] + A[j] + A[k] > W) {
                    break;
                }
                S.insert(A[i] + A[j] + A[k]);
            }
        }
    }
    cout << S.size() << endl;
}