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
int dp[10000][17];

int solve(int id , int mask){
    if(id > n)
        return 0;
    if(id == n)
        return mask == 0;
    int &res = dp[id][mask];
    if(res != -1)
        return res;
    res = 0;
    if(mask == 15){
        res += solve(id + 1 , 0);
    }
    else{
        if(!mask){
            res += solve(id + 1 , 0);
        }
        if(!(mask & 3)){
            int temp = 0;
            for(int i = 2 ; i < 4 ; ++i){
                if(!(mask & (1<<i)))
                    temp |= (1<<i);
            }
            res += solve(id + 1 , temp);
        }
        if(!(mask & 6)){
            int temp = 0;
            if(!(mask & 1))
                temp |= 1;
            if(!(mask & (1<<3)))
               temp |= (1<<3);
            res += solve(id + 1 , temp);
        }
        if(!(mask & 12)){
            int temp = 0;
            for(int i = 0 ; i < 2 ; ++i)
                if(!(mask & (1<<i)))
                    temp |= (1<<i);
            res += solve(id + 1 , temp);
        }
        int temp = 0;
        for(int i = 0 ; i < 4 ; ++i)
            if(!(mask & (1<<i)))
                temp |= (1<<i);
        res += solve(id + 1 , temp);
    }
    return res;
}


int main(){

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        sc(n);
        mem(dp , -1);
        int ans = solve(0 , 0);
        printf("%d %d\n" , ++cases , ans);
    }


return 0;
}
