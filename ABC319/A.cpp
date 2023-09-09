#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// ksun48 3679
// Benq 3658
// Um_nik 3648
// apiad 3638
// Stonefeang 3630
// ecnerwala 3613
// mnbvmar 3555
// newbiedmy 3516
// semiexp 3481
signed main() {
    map<string, int> mp;
    mp["tourist"] = 3858;
    mp["ksun48"] = 3679;
    mp["Benq"] = 3658;
    mp["Um_nik"] = 3648;
    mp["apiad"] = 3638;
    mp["Stonefeang"] = 3630;
    mp["ecnerwala"] = 3613;
    mp["mnbvmar"] = 3555;
    mp["newbiedmy"] = 3516;
    mp["semiexp"] = 3481;

    string S;
    cin >> S;

    cout << mp[S] << endl;
}