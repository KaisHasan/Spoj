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

int dp[222][12][222];
int n;
int solve(int m , int id , int lst){
    if(m < 0)
        return 0;
    if(id == n){
        return m == 0;
    }
    int &res = dp[m][id][lst];
    if(res != -1)
        return res;
    res = 0;
    for(int i = lst ; i <= m ; ++i){
        res += solve(m - i , id + 1 , i);
    }
    return res;
}
vi v;
int k;
void f(int m , int id , int lst){
    if(m < 0)
        return;
    if(id == n){
        return;
    }
    int res = solve(m , id , lst);
    for(int i = lst ; i <= m ; ++i){
        int temp = solve(m - i , id + 1 , i);
        if(k <= temp){
            v.pb(i);
            f(m - i , id + 1 , i);
            break;
        }
        else{
            k -= temp;
        }
    }
}


int main(){

    int t;
    sc(t);
    while(t--){
        int m;
        sc(m);sc(n);sc(k);
        mem(dp , -1);
        v.clear();
        f(m , 0 , 1);
        for(auto i : v)
            printf("%d " , i);
        blank;
    }


return 0;
}
