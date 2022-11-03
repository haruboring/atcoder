#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int cnt = 0;
    rep(i, N) {
        string number = to_string(i + 1);
        int sum = 0;
        rep(j, number.size()) {
            sum += (number[j] - '0');
        }
        if (A <= sum && sum <= B) {
            cnt += i + 1;
        }
    }
    cout << cnt << endl;
}