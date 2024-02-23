#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    double deg, dis;
    cin >> deg >> dis;

    string dir;
    if (112.5 <= deg && deg < 337.5) {
        dir = "NNE";
    } else if (337.5 <= deg && deg < 562.5) {
        dir = "NE";
    } else if (562.5 <= deg && deg < 787.5) {
        dir = "ENE";
    } else if (787.5 <= deg && deg < 1012.5) {
        dir = "E";
    } else if (1012.5 <= deg && deg < 1237.5) {
        dir = "ESE";
    } else if (1237.5 <= deg && deg < 1462.5) {
        dir = "SE";
    } else if (1462.5 <= deg && deg < 1687.5) {
        dir = "SSE";
    } else if (1687.5 <= deg && deg < 1912.5) {
        dir = "S";
    } else if (1912.5 <= deg && deg < 2137.5) {
        dir = "SSW";
    } else if (2137.5 <= deg && deg < 2362.5) {
        dir = "SW";
    } else if (2362.5 <= deg && deg < 2587.5) {
        dir = "WSW";
    } else if (2587.5 <= deg && deg < 2812.5) {
        dir = "W";
    } else if (2812.5 <= deg && deg < 3037.5) {
        dir = "WNW";
    } else if (3037.5 <= deg && deg < 3262.5) {
        dir = "NW";
    } else if (3262.5 <= deg && deg < 3487.5) {
        dir = "NNW";
    } else {
        dir = "N";
    }

    int w;
    dis = dis / 60;
    dis = round(dis * 10) / 10;
    debug(dis);
    if (dis <= 0.2) {
        cout << "C 0" << endl;
    } else if (0.3 <= dis && dis <= 1.5) {
        cout << dir << " 1" << endl;
    } else if (1.6 <= dis && dis <= 3.3) {
        cout << dir << " 2" << endl;
    } else if (3.4 <= dis && dis <= 5.4) {
        cout << dir << " 3" << endl;
    } else if (5.5 <= dis && dis <= 7.9) {
        cout << dir << " 4" << endl;
    } else if (8.0 <= dis && dis <= 10.7) {
        cout << dir << " 5" << endl;
    } else if (10.8 <= dis && dis <= 13.8) {
        cout << dir << " 6" << endl;
    } else if (13.9 <= dis && dis <= 17.1) {
        cout << dir << " 7" << endl;
    } else if (17.2 <= dis && dis <= 20.7) {
        cout << dir << " 8" << endl;
    } else if (20.8 <= dis && dis <= 24.4) {
        cout << dir << " 9" << endl;
    } else if (24.5 <= dis && dis <= 28.4) {
        cout << dir << " 10" << endl;
    } else if (28.5 <= dis && dis <= 32.6) {
        cout << dir << " 11" << endl;
    } else if (32.7 <= dis) {
        cout << dir << " 12" << endl;
    }
}
