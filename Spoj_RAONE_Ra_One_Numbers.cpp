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

ll dp[10][100][100];
int len;

ll F(int dig , int sume , int sumo){
    if(!dig){
        return (sume - sumo == 1);
    }
    ll &res = dp[dig][sume][sumo];
    if(res != -1)
        return res;
    res = 0;
    for(int i = 0 ; i < 10 ; ++i){
        if((dig-1) & 1)
            res += F(dig - 1 , sume + i , sumo);
        else
            res += F(dig - 1 , sume , sumo + i);
    }
    return res;
}

ll solve(int x){
    string s = to_string(x);
    int n = s.size();
    int sume = 0 , sumo = 0;
    ll ans = 0;
    len = n;
    mem(dp,-1);
    for(int i = 0 ; i < len ; ++i){
        --n;
        int d = s[i] -  '0';
        for(int j = 0 ; j < d ; ++j){
            if(n & 1)
                ans += F(n , sume + j , sumo);
            else
                ans += F(n , sume , sumo + j);
        }
        if(n & 1)
            sume += d;
        else
            sumo += d;
    }
    return ans;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int a, b;
        sc(a);sc(b);
//        printf("solve b == %d , solve a == %d\n" , solve(b+1) , solve(a));
        ll res = solve(b + 1) - solve(a);
        printf("%lld\n" , res);
    }




return 0;
}
