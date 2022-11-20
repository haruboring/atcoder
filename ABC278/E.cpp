#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H,W,N,h,w;cin>>H>>W>>N>>h>>w;
    vector<vector<int>> A(H,vector<int>(N));
    vector<int> all_(N+1),cp(N+1);
    rep(i,H){
        rep(j,W){
            cin>>A[i][j];
            all_[A[i][j]]++;
            cp[A[i][j]]++;
        }
    }
    map<int,int> ans;
    vector<vector<int>> ans_cnt(H-h+1,vector<int>(W-w+1));
    set<int> S;
    rep(i,H){
        rep(j,W){
            ans[A[i][j]]--;
        }
    }
    rep(i,h){
        rep(j,w){
            ans[A[i][j]]++;
        }
    }
    int cnt = 0;
    rep(i,400){
        if(ans[i]!=0){
            cnt++;
        }
    }
    ans_cnt[0][0]=cnt;
    rep(i, H-h){
        rep(j,W-w){
            ans_cnt[i][j+1]=ans_cnt[i][j];
            rep(k,h){
                ans[A[i+k][j]]--;
                if(ans[A[i+k][j]]==0){
                    ans_cnt[i][j+1]--;
                }
            }
            rep(k,h){
                ans[A[i+k][j+w+1]]++;
                if(ans[A[k][j+w+1]]==1){
                    ans_cnt[i][j+1]++;
                }
            }
        }
        ans_cnt[i][0]=ans_cnt[i][0];
        rep(k,w){
            ans[A[i][k]]--;
            if(ans[A[i][k]]==0){
                ans_cnt[i][1]--;
            }
        }
        rep(k,h){
            ans[A[k+1+i][k]]++;
            if(ans[A[i+1+i][k]]==1){
                ans_cnt[i+1][0]++;
            }
        }
    }
    rep(i,H-h+1){
        rep(j,W-w+1){
            cout << ans_cnt[i][j] << " ";
        }
        cout << endl;
    }
}