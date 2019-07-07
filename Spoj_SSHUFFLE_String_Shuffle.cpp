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


string s1 , s2 , t;
int n1 ,n2 , m;
ll dp[66][66][66];

ll solve(int l , int r , int id){
    if(id == m){
        return 1ll;
    }
    ll &res = dp[l][r][id];
    if(res != -1)
        return res;
    res = 0;
    for(int i = l ; i < n1 ; ++i){
        if(s1[i] == t[id])
            res += solve(i + 1 , r , id + 1);
    }
    for(int i = r ; i < n2 ; ++i){
        if(s2[i] == t[id])
            res += solve(l , i + 1 , id + 1);
    }
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int c;
    sc(c);
    while(c--){
        cin>>s1>>s2>>t;
        n1 = s1.size();
        n2 = s2.size();
        m = t.size();
        mem(dp,-1);
        ll res = solve(0,0,0);
        printf("%lld\n" , res);
    }




return 0;
}
