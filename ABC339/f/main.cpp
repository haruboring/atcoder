#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

#define _MIN_
#define _MOUT_
#define _MINOUT_
#define M_BEGIN_END(__MA__) __MA__.begin(), __MA__.end()
#define M_RBEGIN_REND(__MA__) __MA__.rbegin(), __MA__.rend()

class BigInteger final {
   public:
    BigInteger(_MIN_ const int64_t value) noexcept {
        this->mIsNegative = ((value >> 63) & 0b1) == true;
        int64_t _val = this->mIsNegative ? (value * -1) : value;
        while (_val != 0) {
            mValue.emplace_back(_val % 10);
            _val /= 10;
        }
    };

    BigInteger(_MIN_ const std::string &value) : mIsNegative{false} {
        if (value.empty() == false) {
            int32_t startId = 0;
            const int32_t len = static_cast<int32_t>(value.size());
            if (value[0] == '-') {
                this->mIsNegative = true;
                startId = 1;
            }
            for (int32_t i = len - 1; i >= startId; --i) {
                if (value[i] < '0' || value[i] > '9') {
                    throw std::runtime_error("value is not numeric character.");
                }
                this->mValue.emplace_back(value[i] - '0');
            }
        }
    }

    [[nodiscard]] std::string ToString() const noexcept {
        auto it = std::find_if(M_RBEGIN_REND(this->mValue), [](const uint8_t &val) { return val != 0; });
        if (it == this->mValue.rend()) {
            return "0";
        } else {
            std::string result = {};
            if (this->mIsNegative == true) {
                result += '-';
            }

            for (; it != this->mValue.rend(); ++it) {
                result += *it + '0';
            }
            return result;
        }
    }

    [[nodiscard]] friend BigInteger operator*(_MIN_ const BigInteger &a, _MIN_ const BigInteger &b) noexcept {  // Use karatsuba equation! O(N^(lg3))
        // * N is maximum unit
        return BigInteger::__KaratsubaMultiplyEntry(a, b);
    }

   private:
    using TContainer = std::vector<int16_t>;
    BigInteger(_MIN_ const BigInteger::TContainer &valueContainer, _MIN_ const bool isNegative) noexcept {
        this->mValue = valueContainer;
        this->mIsNegative = isNegative;
    }

    [[nodiscard]] static BigInteger
    __KaratsubaMultiplyEntry(_MIN_ const BigInteger &a, _MIN_ const BigInteger &b) noexcept {
        const TContainer unsignedResult = BigInteger::__ProcessKaratsuba(a.mValue, b.mValue);
        const bool isNegative = (a.mIsNegative ^ b.mIsNegative) == true;

        const BigInteger result{unsignedResult, isNegative};
        return result;
    }

    [[nodiscard]] static TContainer
    __ProcessKaratsuba(_MIN_ const TContainer &a, _MIN_ const TContainer &b) noexcept {
        const int32_t aUnitSize = static_cast<int32_t>(a.size());
        const int32_t bUnitSize = static_cast<int32_t>(b.size());
        // Integrity  : If aUnitSize is smaller than bUnitSize, swap each other and execute.
        if (aUnitSize < bUnitSize) {
            return __ProcessKaratsuba(b, a);
        }
        // Base  : If aUnitSize or bUnitSize is 0 (no value), just return 0.
        if (aUnitSize == 0 || bUnitSize == 0) {
            return TContainer(0);
        }
        // Base : If aUnitSize or bUnitSize is 2, just multiply each other O(N^2) but might be fast.
        if (aUnitSize <= 2) {
            return BigInteger::__Multiply(a, b);
        }

        // Normal case...
        const int32_t halfUnit = aUnitSize / 2;
        TContainer a0(a.begin(), a.begin() + halfUnit);
        TContainer a1(a.begin() + halfUnit, a.end());
        TContainer b0(b.begin(), b.begin() + std::min(halfUnit, bUnitSize));
        TContainer b1(b.begin() + std::min(halfUnit, bUnitSize), b.end());

        // z0 = a1 * b1, z2 = a0 * b0
        const TContainer z0 = __ProcessKaratsuba(a1, b1);
        const TContainer z2 = __ProcessKaratsuba(a0, b0);

        // a1 + a0, b1 + b0
        const TContainer ar = __KaratsubaAddContainer(a1, 0, a0);
        const TContainer br = __KaratsubaAddContainer(b1, 0, b0);
        // calculate z1
        TContainer z1 = __ProcessKaratsuba(ar, br);
        __KaratsubaSubFrom(z1, z0);
        __KaratsubaSubFrom(z1, z2);

        // calculate a * b finally!
        TContainer result = {};
        result = __KaratsubaAddContainer(z2, 0, result);
        result = __KaratsubaAddContainer(z1, halfUnit, result);
        result = __KaratsubaAddContainer(z0, halfUnit * 2, result);
        __Normalize(result);
        return result;
    }

    ///
    /// @brief a * 10^k + b
    ///
    [[nodiscard]] static TContainer
    __KaratsubaAddContainer(_MIN_ const TContainer &a, _MIN_ const uint32_t k, _MIN_ const TContainer &b) noexcept {
        const int32_t len = static_cast<int32_t>(a.size());

        TContainer result = b;
        result.resize(std::max(b.size(), a.size() + k) + 1);

        for (int32_t i = 0; i < len; ++i) {
            result[i + k] += a[i];
            if (result[i + k] > 10) {
                result[i + k] -= 10;
                result[i + k + 1] += 1;
            }
        }

        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }
        return result;
    }

    [[nodiscard]] static TContainer
    __Multiply(_MIN_ const TContainer &a, _MIN_ const TContainer &b) noexcept {
        const int32_t aUnitSize = static_cast<int32_t>(a.size());
        const int32_t bUnitSize = static_cast<int32_t>(b.size());
        // Integrity Check : If aUnitSize is smaller than bUnitSize, swap each other and execute.
        if (aUnitSize < bUnitSize) {
            return __Multiply(b, a);
        }

        TContainer result(aUnitSize + bUnitSize + 1, 0);
        for (int32_t i = 0; i < bUnitSize; ++i) {
            for (int32_t j = 0; j < aUnitSize; ++j) {
                result[i + j] += a[j] * b[i];
            }
        }

        __Normalize(result);
        return result;
    }
    static void __KaratsubaSubFrom(_MOUT_ TContainer &a, _MIN_ const TContainer &b) noexcept {  // Assertion
        assert(a.size() >= b.size());
        // Body
        int len = b.size();
        a.resize(std::max(a.size(), b.size()) + 1);

        for (int i = 0; i < len; i++) {
            a[i] -= b[i];

            if (a[i] < 0) {
                a[i] += 10;
                a[i + 1] -= 1;
            }
        }
    }

    ///
    /// @brief Normalize value container and reflect carry or borrow flag to container.
    /// @param value Value container to be updated.
    ///
    static void __Normalize(_MINOUT_ TContainer &value) noexcept {
        value.push_back(0);
        //
        const int32_t len = static_cast<int32_t>(value.size());
        for (int i = 0; i < len; ++i) {
            if (value[i] < 0) {
                int32_t borrow = (std::abs(value[i]) + 9) / 10;
                value[i + 1] -= borrow;
                value[i] += borrow * 10;
            } else {
                value[i + 1] += value[i] / 10;
                value[i] %= 10;
            }
        }
        //
        while (value.size() > 1 && value.back() == 0) {
            value.pop_back();
        }
    }

    /// Example) integer value 1258
    /// [0][1][2][3]
    ///  8  5  2  1
    TContainer mValue = {};
    bool mIsNegative : 1;
};

signed main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }

    map<string, int> counter;
    rep(i, N) {
        counter[S[i]]++;
    }
    set<string> st;
    rep(i, N) {
        st.insert(S[i]);
    }

    int ans = 0;
    rep(i, N){
        rep(j, N){
            string seki = (BigInteger(S[i]) * BigInteger(S[j])).ToString().c_str();
            if (st.count(seki)) {
                ans+=counter[seki];
            }
        }
    }

    cout << ans << endl;
}
