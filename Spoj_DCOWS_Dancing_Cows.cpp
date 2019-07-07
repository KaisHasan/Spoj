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
const ll inf = 1e10+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , m;
int c[5005] , b[5005];
ll dp[5005][5005];

ll solve(int l , int r){
    if(l == n)
        return 0;
    if(r == m)
        return inf;
    ll &res = dp[l][r];
    if(res != -1)
        return res;
    res = inf;
    res = min(res , solve(l , r + 1));
    res = min(res , solve(l + 1 , r + 1) + abs(c[r] - b[l]));
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < n ; ++i)
        sc(b[i]);
    for(int i = 0 ; i < m ; ++i)
        sc(c[i]);
    sort(b , b + n);
    sort(c , c + m);
    mem(dp , -1);
    ll res = solve(0 , 0);
    printf("%lld\n" , res);

return 0;
}
