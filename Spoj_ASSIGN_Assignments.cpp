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
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int a[22][22];
ll dp[21][1<<20];
int n;

ll solve(int id , int mask){
    if(id == n)
        return mask == ((1<<n)-1);
    ll &res = dp[id][mask];
    if(res != -1)
        return res;
    res = 0;
    for(int i = 0 ; i < n ; ++i){
        if(a[id][i] && !(mask & (1<<i)))
            res += solve(id + 1 , mask | (1<<i));
    }
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        mem(dp,-1);
        sc(n);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                sc(a[i][j]);
            }
        }
        ll ans = solve(0 , 0);
        printf("%lld\n" , ans);
    }




return 0;
}
