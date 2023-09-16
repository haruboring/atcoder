#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll all_sum = ((1 + N) / 2) * N;
    if(N%2==1){
        all_sum+=(1+N)
    }
    ll A_sum = A * ((1 + N / A) / 2) * (N / A);
    if ((N / A) % 2 != 0) {
        A_sum += A * (1 + N / A) / 2;
    }
    ll B_sum = B * ((1 + N / B) / 2) * (N / B);
    if ((N / B) % 2 != 0) {
        B_sum += B * (1 + N / B) / 2;
    }
    ll AB_sum = (A * B) * ((1 + N / (A * B)) / 2) * (N / (A * B));
    if ((N / A * B) % 2 != 0) {
        AB_sum += A * B * (1 + N / A * B) / 2;
    }
    cout << all_sum - A_sum - B_sum + AB_sum << endl;
}