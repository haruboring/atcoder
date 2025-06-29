#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    map<string, int> m;
    m["tourist"] = 3858;
    m["ksun48"] = 3679;
    m["Benq"] = 3658;
    m["Um_nik"] = 3648;
    m["apiad"] = 3638;
    m["Stonefeang"] = 3630;
    m["ecnerwala"] = 3613;
    m["mnbvmar"] = 3555;
    m["newbiedmy"] = 3516;
    m["semiexp"] = 3481;

    string S;
    cin >> S;

    cout << m[S] << endl;
}
