#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int A,B,C,D;cin>>A>>B>>C>>D;
    if(A<C){
        cout << "Takahashi" << endl;
        return 0;
    }
    else if(A==C){
        if(B<=D){
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
}