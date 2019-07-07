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

int dp[33][8];
int n;

int solve(int id , int mask){
    if(id > n)
        return 0;
    if(id == n){
        return mask == 0;
    }
    int &res = dp[id][mask];
    if(res != -1)
        return res;
    res = 0;
    if(mask == 7)
        res += solve(id + 1 , 0);
    else{
        if(!(mask & 3)){
            if(mask & (1<<2))
                res += solve(id + 1 , 0);
            else
                res += solve(id + 1 , 1<<2);
        }
        if(!(mask & 6)){
            if(mask & 1)
                res += solve(id + 1 , 0);
            else
                res += solve(id + 1 , 1);
        }
        int temp = 0;
        for(int i = 0 ; i < 3 ; ++i)
            if(!(mask & (1<<i)))
                temp |= (1<<i);
        res += solve(id + 1 , temp);
    }
    return res;
}


int main(){

    while(1){
        sc(n);
        if(n == -1)
            break;
        mem(dp , -1);
        int ans = solve(0 , 0);
        printf("%d\n" , ans);
    }


return 0;
}
