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
pi a[202];
int dp[606][606];

int solve(int w , int h){
    int &res = dp[w][h];
    if(res != -1)
        return res;
    res = w * h;
    for(int i = 0 ; i < n ; ++i){
        if(a[i].first <= w && a[i].second <= h){
            res = min(res , solve(w - a[i].first , a[i].second) + solve(w , h - a[i].second));
            res = min(res , solve(w - a[i].first , h) + solve(a[i].first , h - a[i].second));
        }
    }
    return res;
}


int main(){

    int t;
    sc(t);
    while(t--){
        int w , h;
        sc(w);sc(h);
        sc(n);
        for(int i = 0 ; i < n ; ++i){
            int x , y;
            sc(x);sc(y);
            a[i] = MP(x,y);
        }
        mem(dp , -1);
        int ans = solve(w , h);
        printf("%d\n" , ans);
    }


return 0;
}
