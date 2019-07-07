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
const ll inf = 1e17+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll dp[200][200];
int n;
string s;
ll solve(int l , int r){
    if(l == r)
        return (s[l] - '0');
    ll &res = dp[l][r];
    if(res != -1)
        return res;
    res = 0;
    for(int i = l + 1 ; i < r ; i += 2){
        if(s[i] == '+')
            res = max(res , solve(l , i - 1) + solve(i + 1 , r));
        else
            res = max(res , solve(l , i - 1) * solve(i + 1 , r));
    }
    return res;
}

ll father(int l , int r){
    if(l == r){
        return (s[l] - '0');
    }
    ll &res = dp[l][r];
    if(res != -1)
        return res;
    res = inf;
    for(int i = l + 1 ; i < r ; i += 2){
        if(s[i] == '+')
            res = min(res , father(l , i - 1) + father(i + 1 , r));
        else
            res = min(res , father(l , i - 1) * father(i + 1 , r));
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
        cin>>s;
        n = s.size();
        ll lisa = solve(0 , n - 1);
        mem(dp,-1);
        ll fat = father(0 , n - 1);
        printf("%lld %lld" , lisa , fat);
        blank;
    }



return 0;
}
