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

int n;
int coins[6];
int dp[6][MAX];
int solve(int id , int rem , int cnt = 2*MAX){
    if(id == n){
        if(rem)
            return 0;
        return 1;
    }
    if(rem < 0)
        return 0;
    if(!rem)
        return 1;
    int &res = dp[id][rem];
    if(res != -1)
        return res;
    res = 0;
    for(int i = 1 ; i <= cnt ; ++i){
        rem -= coins[id];
        if(rem < 0)
            break;
        res |= solve(id + 1 , rem  , i);
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int x;
    sc(x);
    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(coins[i]);
    mem(dp , -1);
    int ans = solve(0 , x);
    if(ans)
        printf("YES");
    else
        printf("NO");

return 0;
}
