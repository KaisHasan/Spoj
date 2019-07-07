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
#define ever ;;
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int a[202];
int dp[202][202][202];
int n;

int solve(int id , int lstI , int lstD){
    if(id == n)
        return 0;
    int &res = dp[id][lstI][lstD];
    if(res != -1)
        return res;
    res = inf;
    res = min(res , solve(id + 1,  lstI , lstD) + 1);
    int mx;
    if(lstI == n)
        mx = -1;
    else
        mx = a[lstI];
    int mn;
    if(lstD == n)
        mn = inf;
    else
        mn = a[lstD];
    if(a[id] > mx)
        res = min(res , solve(id + 1 , id , lstD));
    if(a[id] < mn)
        res = min(res , solve(id + 1 , lstI , id));
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    for(ever){
        mem(dp,-1);
        sc(n);
        if(n == -1)
            break;
        for(int i = 0 ; i < n ; ++i)
            sc(a[i]);

        int ans = solve(0 , n , n);
        printf("%d\n" , ans);
    }




return 0;
}
