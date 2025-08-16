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

//UnionTree
struct UnionFind{
    vector<int> par;

    UnionFind(int n): par(n){
        rep(i,0,n) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x,int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> k(n);
    rep(i,0,n) cin >> k[i];
    int ans = INF;
    for(int bit = 0;bit < (1<<n);++bit){
        int suma = 0, sumb = 0;
        for(int i = 0;i < n;++i){
            if(bit & (1 << i)) suma += k[i];
            else sumb += k[i];
        }
        chmin(ans, max(suma, sumb));
    }
    cout << ans << nl;
}