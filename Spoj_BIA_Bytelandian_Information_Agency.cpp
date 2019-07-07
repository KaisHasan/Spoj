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
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n, m;
vi adj[MAX];
int dfs_num[MAX] , dfs_low[MAX];
int dfs_parent[MAX];
int dfsNumberCounter;
int articulation_vertex[MAX];
int dfsRoot;

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            dfs_parent[v] = u;
            articulationPointAndBridge(v);
            if(dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
        else if(v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u] , dfs_num[v]);
        }
    }
}

int main(){
freopen("output.txt" , "w" , stdout);
freopen("input.txt" , "r" , stdin);

    int t = 10;
    while(t--){
        dfsNumberCounter = 0;
        memset(dfs_num , -1 , sizeof(dfs_num));
        memset(dfs_low , 0 , sizeof(dfs_low));
        memset(dfs_parent , 0 , sizeof(dfs_parent));
        memset(articulation_vertex , 0 , sizeof(articulation_vertex));
        sc(n);sc(m);
        for(int i = 0 ;i < m ; ++i){
            int u , v;
            sc(u);sc(v);
            adj[u].pb(v);
        }
        vi res;
        res.clear();
        //res.pb(1);
        dfsRoot = 1;
        articulationPointAndBridge(1);
        articulation_vertex[dfsRoot] = 1;
        for(int j = 1 ; j <= n ; ++j){
            if(articulation_vertex[j]){
                res.pb(j);
            }
        }
        printf("%d\n" , (int)res.size());
        for(auto i : res)
            printf("%d " , i);
        blank;
        for(int i = 0 ;i <= n ; ++i)
            adj[i].clear();
    }



return 0;
}
