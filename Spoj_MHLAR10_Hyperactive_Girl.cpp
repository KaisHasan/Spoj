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
const int MOD = 1e8;
const double PI = acos(-1.0);
const double eps = 1e-7;

int m , n;
pi a[105];
int dp[105][105][105];

int solve(int id , int lst , int lstlst){
    if(id == n){
        if(lst == n)
            return 0;
        return a[lst].second == m;
    }
    int &res = dp[id][lst][lstlst];
    if(res != -1)
        return res;
    res = 0;
    int en;
    if(lst == n)
        en = 0;
    else
        en = a[lst].second;
    int st;
    if(lstlst == n)
        st = -1;
    else
        st = a[lstlst].second;
    if(lst != n)
        st = max(st , a[lst].first);
    res = (res + solve(id + 1 , lst , lstlst))%MOD;
    if(a[id].first <= en && a[id].first > st && a[id].second > en)
        res = (res + solve(id + 1 , id , lst))%MOD;
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        sc(m);sc(n);
        if(n + m == 0)
            break;
        for(int i = 0 ; i < n ; ++i){
            int x , y;
            sc(x);sc(y);
            a[i] = MP(x,y);
        }
        mem(dp,-1);
        sort(a , a + n);
//        pla;
//            for(int i = 0 ; i < n ; ++i){
//                printf("%d: st == %d , en == %d\n" , i , a[i].first , a[i].second);
//            }
//        pla;
        if(a[0].first > 0){
            printf("0\n");
            continue;
        }
        int ans = solve(0 , n , n);
        printf("%d\n" , ans);
    }




return 0;
}
