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
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

vector<int> adj[MAX];
int n , m;
int vis[MAX];
int par[MAX];
vector<int> res;

void dfs(int v){
    vis[v] = 1;
    for(auto node : adj[v]){
        if(!vis[node])
            dfs(node);
    }
    res.pb(v);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 1 ; i <= m ; ++i){
        int x;
        int k;
        sc(k);
        while(k--){
            sc(x);
            if(x == i)
                continue;
            adj[i].pb(x);
        }
    }
    for(int i = 1 ; i <= n ; ++i)
        if(!vis[i])
            dfs(i);
    reverse(all(res));
    par[res[0]] = 0;
    for(int i = 1 ; i < n ; ++i){
        par[res[i]] = res[i-1];
    }

    for(int i = 1 ; i<=n ; ++i)
        printf("%d\n" , par[i]);

return 0;
}
