#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

const int MOD = 1000000000;  // これのあまりを見ることで下9桁を求められる
const int MAX = 10+5;  // N, Mが10以下なので、余裕を持って15にしている
int fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

int COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(int argc, char *argv[]) {
    int M, N, other_input;

    if (!(cin >> M >> N)) {
        return 100;
    }
    // if (cin >> other_input) {
    //     return 100;
    // }

    // if (!((1 <= M && M <= 10) && (1 <= N && N <= 10))) {
    //     return 100;
    // }

    // if ((M * N) % 2 == 1) {
    //     cout << setfill('0') << setw(9) << 0 << endl;
    //     return 0;
    // }

    int all_cnt = M * N;
    int half_cnt = all_cnt / 2;
    // 求める答えは all_cnt C half_cnt である

    COMinit();
    cout << M << " " << N << endl;
    cout << setfill('0') << setw(9) << COM(all_cnt, half_cnt) << endl;

}
