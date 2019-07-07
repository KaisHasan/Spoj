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

int dp[MAX][2];
vi adj[MAX];
bool is_leaf(int node){
    if(node == 1)
        return false;
    return (int)adj[node].size() == 1;
}
int solve(int node , int flg , int par = -1){
    int &res = dp[node][flg];
    if(res != -1)
        return res;
    if(is_leaf(node)){
        res = flg;
    }
    else if(flg){
        res = 1;
        for(auto v : adj[node]){
            if(v == node || v == par)
                continue;
            res += min(solve(v , 1 , node) , solve(v , 0 , node));
        }
    }
    else{
        res = 0;
        for(auto v : adj[node]){
            if(v == node || v == par)
                continue;
            res += solve(v , 1 , node);
        }
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    int m = n - 1;
    while(m--){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    mem(dp,-1);
    int res = min(solve(1 , 0) , solve(1 , 1));
    printf("%d" , res);


return 0;
}
