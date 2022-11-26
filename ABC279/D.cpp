#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll A, B;

double f(double x) {
    double ot = sqrt(1 + x);
    return -A / (2 * pow(ot, 3)) + B;
}

int main() {
    cin >> A >> B;
    ll inM;
    if(f(0) >0){
        inM=0;
    }
    else{
        ll L = 0, R = 100000000000000000, M;
        rep(i,1000000){
            M = (L + R) / 2;
            if (f(M)*f(M+1) < 0) {
                break;
            } else if (f(M) > 0) {
                R = M;
            } else {
                L = M;
            }
        }
        inM=M;
        if(abs(f(M)) > abs(f(M+1))){
            inM++;
        }
    }
    double ot = sqrt(1 + inM);
    double ans = A / ot + B * inM;
    cout << fixed << setprecision(14) << ans << endl;
}