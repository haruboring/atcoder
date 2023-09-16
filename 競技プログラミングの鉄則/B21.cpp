#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    /*
    問題文
    太郎君は、長さ N の文字列 S に対して以下の操作を行うことで、回文を作りたいです。

    S の中から（連続するとは限らない）文字を取り除く。
    残った文字を順番通りに連結する。
    最長何文字の回文を作ることができるか、出力するプログラムを作成してください。

    制約
    1≤N≤1000
    文字列 S は英小文字からなる
    */
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<int>> dp(N,vector<int>(N));
    dp[0][0]=1;
    rep(i,N){
        rep(j,N){
            if(i==0 && j==0){
                continue;
            }
            
        }
    }
}