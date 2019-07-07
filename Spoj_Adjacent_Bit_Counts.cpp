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
const int MAX = 200;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int dp[MAX][MAX][2];
int solve(int id , int rem , int flg){
    if(id == n){
        if(rem != 0)
            return 0;
        return 1;
    }
    int &res = dp[id][rem][flg];
    if(res != -1)
        return res;
    res = 0;
    res += solve(id + 1 , rem - flg , 1);
    res += solve(id + 1 , rem , 0);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int cases;
        sc(cases);
        sc(n);
        int k;
        sc(k);
        mem(dp , -1);
        int res = solve(0 , k , 0);
        printf("%d %d" , cases , res);
        blank;
    }



return 0;
}
