#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vpi main_goods;
vpi atc[MAX];
int ID[MAX];
int n;
ll dp[66][33000];
ll solve(int id , int rem){
    if(rem < 0)
        return -inf;
    if(id == n)
        return 0;
    if(rem == 0)
        return 0;
    ll &res = dp[id][rem];
    if(res != -1)
        return res;
    res = -2;
    res = max(res , solve(id + 1 ,rem));
    res = max(res , solve(id + 1 , rem - main_goods[id].first) + ((ll)main_goods[id].first*main_goods[id].second));
    int Nrem = main_goods[id].first;
    ll c = (ll)main_goods[id].second*main_goods[id].first;
    for(auto i : atc[ID[id]]){
        Nrem += i.first;
        c += ((ll)i.second*i.first);
        res = max(res , solve(id + 1, rem - Nrem) + c);
    }
    if((int)atc[ID[id]].size() == 2){
        res = max(res , solve(id + 1 , rem - atc[ID[id]][1].first - main_goods[id].first) + (ll)(atc[ID[id]][1].first * atc[ID[id]][1].second)+(main_goods[id].second * main_goods[id].first));
    }
    return res;
}




int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int cap;
        sc(cap);
        int m;
        sc(m);
        mem(dp,-1);
        mem(ID , -1);
        for(int i = 1 ; i <= m ; ++i){
            atc[i].clear();
        }
        main_goods.clear();
        for(int i = 0 ; i < m ; ++i){
            int w , c , par;
            sc(w);sc(c);sc(par);
            if(par != 0)
                atc[par].pb(MP(w , c));
            else{
                main_goods.pb(MP(w,c));
                ID[(int)main_goods.size()-1] = i + 1;
            }
        }
        n = (int)main_goods.size();
        ll res = solve(0 , cap);
        printf("%lld\n" , res);
    }



return 0;
}
