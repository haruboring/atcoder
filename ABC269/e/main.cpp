#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    int ai = 0, aj = 0;

    int il = 0, ir = N - 1, jl = 0, jr = N - 1;
    while (ir - il > 0) {
        int im = (il + ir) / 2;

        debug(im);
        cout << "? " << il + 1 << " " << im + 1 << " " << jl + 1 << " " << jr + 1 << endl;
        int cnt;
        cin >> cnt;

        if (cnt < im - il + 1) {
            ir = im;
        } else {
            il = im + 1;
        }

        debug(il);
        debug(ir);
    }

    ai = il;

    il = 0, ir = N - 1, jl = 0, jr = N - 1;
    while (jr - jl > 0) {
        int jm = (jl + jr) / 2;
        cout << "? " << il + 1 << " " << ir + 1 << " " << jl + 1 << " " << jm + 1 << endl;
        int cnt;
        cin >> cnt;

        if (cnt < jm - jl + 1) {
            jr = jm;
        } else {
            jl = jm + 1;
        }
    }

    aj = jl;

    cout << "! " << ai + 1 << " " << aj + 1 << endl;
}
