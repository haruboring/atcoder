#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = unsigned long long;

string multiplyStrings(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string resultStr;
    for (int num : result) {
        if (!(resultStr.empty() && num == 0)) {
            resultStr.push_back(num + '0');
        }
    }

    return resultStr.empty() ? "0" : resultStr;
}

int main() {
    ll A, B;
    cin >> A >> B;

    ll GCD = gcd(A, B);
    ll A_ = A / GCD;
    ll B_ = B / GCD;

    string A_str = to_string(A_);
    string B_str = to_string(B_);
    string GCD_str = to_string(GCD);

    string A_B = multiplyStrings(A_str, B_str);
    string A_B_GCD = multiplyStrings(A_B, GCD_str);

    if (A_B_GCD.size() > 18 && A_B_GCD != "1000000000000000000") {
        cout << "Large" << endl;
    } else {
        cout << stoull(A_B_GCD) << endl;
    }
}