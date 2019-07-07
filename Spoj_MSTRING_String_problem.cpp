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

string s , t;
int n, m;
int dp[1005][1005];

int _find(char c , int st){
    int res = -1;
    for(int i = st ; i < m ; ++i)
        if(t[i] == c)
            return i;
    return m;
}
int solve(int l , int r){
    if(r == m + 1)
        return 1;
    if(l == n)
        return inf;
    int &res = dp[l][r];
    if(res != -1)
        return res;
    res = inf;
    int nxt = _find(s[l] , r);
    res = min(res , solve(l + 1 , nxt + 1) + 1);
    res = min(res , solve(l + 1 , r));
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    cin>>s>>t;
    n = s.size();
    m = t.size();
    mem(dp,-1);
    int res = solve(0,0)-1;
    printf("%d\n" , res);


return 0;
}
