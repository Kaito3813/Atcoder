#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i = a;i < n;i++)
#define rrep(i,a,n) for(int i = n-1;i >= a;i--)
#define nl "\n"

using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,ll>;
using str = string;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9+7;
const int MOD9 = 998244353;

//最小値・最大値更新
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a = b; return true; } return false; }

//小数の桁数指定出力
inline void coutp(double x, int p) { cout << fixed << setprecision(p) << x << '\n'; }


//グリッド探索用の方向配列 
const int dx[4] = {1, 0, -1, 0}; //右、下、左、上
const int dy[4] = {0, 1, 0, -1};


int main(){
    int n,index;
    cin >> n;
    str s,ans;
    cin >> s;
    vector<int> a;
    for(auto c : s){
        if(c == ')'){
            if(!a.empty()){
                int x = a.back();
                a.pop_back();
                ans.erase(ans.begin()+x,ans.end());
            }else{
                ans += c;
            }
        }else if(c == '('){
            ans += c;
            a.push_back((int)ans.size()-1);
        }else{
            ans += c;
            index++;
        }
    }
    cout << ans << nl;
    return 0;
}