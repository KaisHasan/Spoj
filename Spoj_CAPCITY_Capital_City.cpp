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

vector<int> adj[MAX];
int vis[MAX];
vi SCC;
vpi edges;
int dfs_num[MAX] , dfs_low[MAX] , cmp[MAX] , inD[MAX];
int dfsNumberCounter;
int numSCC;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    vis[u] = 1;
    SCC.pb(u);
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            tarjanSCC(v);
        }
        if(vis[v]){
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
    }

    if(dfs_num[u] == dfs_low[u]){
        ++numSCC;
        while(1){
            int v = SCC.back();
            SCC.pop_back();
            vis[v] = 0;
            cmp[v] = numSCC;
            if(u == v)
                break;
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    memset(vis , 0 , sizeof(vis));
    memset(dfs_num , -1 ,sizeof(dfs_num));
    memset(dfs_low , 0 , sizeof(dfs_low));
    mem(inD , 0);
    dfsNumberCounter = numSCC = 0;
    SCC.clear();
    edges.clear();
    int n , m;
    sc(n);sc(m);
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        edges.pb(MP(v,u));
    }
    for(int i = 1 ; i <= n ; ++i){
        if(dfs_num[i] == -1){
            tarjanSCC(i);
        }
    }

    for(auto e : edges){
        int u = e.first;
        int v = e.second;
        if(cmp[u] != cmp[v])
            ++inD[cmp[v]];
    }

    vi res;
    for(int i = 1 ; i <= numSCC  ;++i)
        if(!inD[i])
            res.pb(i);
    if((int)res.size() != 1){
        printf("0");
        return 0;
    }
    int ans = res[0];
    res.clear();
    for(int i = 1 ; i <= n ; ++i){
        if(cmp[i] == ans)
            res.pb(i);
    }
    printf("%d\n" , (int)res.size());
    for(auto i : res)
        printf("%d " , i);

    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear();


return 0;
}
