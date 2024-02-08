#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll X, Y;

ll convert_red_jewel(int);


ll convert_blue_jewel(int level) {
    if (level == 1) {
        return 1;
    }
    return convert_red_jewel(level - 1) + Y * convert_blue_jewel(level - 1);
}

ll convert_red_jewel(int level) {
    if (level == 1) {
        return 0;
    }
    return convert_red_jewel(level - 1) + X * convert_blue_jewel(level);
}

int main() {
    int N;
    cin >> N >> X >> Y;
    cout << convert_red_jewel(N) << endl;
}