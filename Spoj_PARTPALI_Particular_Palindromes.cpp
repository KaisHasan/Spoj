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

int m , n;
ll dp[1005][22];

int power(int x , int y){
    if(!y)
        return 1;
    int res = power(x , y / 2);
    res = (res * res)%m;
    if(y&1)
        res = (res *(x%m))%m;
    return res;
}

int f(int a ,int loc){
    return (a * power(10, loc))%m;
}

ll solve(int mod , int l , int r){
    if(l > r)
        return mod == 0;
    ll &res = dp[mod][l];
    if(res != -1)
        return res;
    res = 0;
    for(int i = (l==0) ; i < 10 ; ++i){
        int temp = mod;
        temp = (temp + f(i,l))%m;
        if(l != r)
            temp = (temp + f(i,r)) % m;
        res += solve(temp , l + 1 , r - 1);
    }
    return res;
}

int main(){

    int t;
    sc(t);
    while(t--){
        mem(dp,-1);
        sc(m);sc(n);
        ll res = solve(0 , 0 , n - 1);
        printf("%lld\n" , res);
    }


return 0;
}
