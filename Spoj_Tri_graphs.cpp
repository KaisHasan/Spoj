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

ll grid[MAX][4];
int n;
ll dp[MAX][4];
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < 3;
}

ll solve(int i , int j){
    if(i == n - 1 && j == 1)
        return 0;
    ll &res = dp[i][j];
    if(res != -1)
        return res;
    res = inf;
    if(valid(i , j + 1)){
        res = min(res , solve(i , j + 1) + grid[i][j+1]);
    }
    if(valid(i + 1 , j - 1)){
        res = min(res , solve(i + 1 , j - 1) + grid[i+1][j-1]);
    }
    if(valid(i + 1 , j)){
        res = min(res , solve(i + 1 , j) + grid[i+1][j]);
    }
    if(valid(i + 1 , j + 1)){
        res = min(res , solve(i + 1 , j + 1) + grid[i+1][j+1]);
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int cases = 0;
    while(1){
        sc(n);
        if(!n)
            break;
        mem(dp , -1);
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < 3 ; ++j)
                cin>>grid[i][j];
        ll res = solve(0 , 1) + grid[0][1];
        printf("%d. %lld\n" ,++cases, res);
    }




return 0;
}
