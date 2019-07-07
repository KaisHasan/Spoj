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
pi a[1001];
int dp[1001][3000];

int solve(int id , int lst){
    if(id == n)
        return 0;
    int &res = dp[id][lst];
    if(res != -1)
        return res;
    res = 0;
    res = max(res , solve(id + 1 , lst));
    if(a[id].second >= lst)
        res = max(res , solve(id + 1 , a[id].second) + 1);
    return res;
}

int main(){

    int t;
    sc(t);
    while(t--){
        mem(dp , -1);
        sc(n);
        for(int i = 0 ; i  <n ; ++i){
            sc(a[i].first);
            a[i].first += 1005;
        }
        for(int i = 0 ; i < n ; ++i){
            sc(a[i].second);
            a[i].second += 1005;
        }
        sort(a , a + n);
        int ans = solve(0 , 0);
        printf("%d\n" , ans);
    }


return 0;
}
