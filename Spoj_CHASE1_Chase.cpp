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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

struct edge{
    int u ,v , w;
    edge(int _u , int _v , int _w = 0){
        u = _u;
        v = _v;
        w = _w;
    }
};
int n , m , A , B;
vector<int> adj[MAX];
int dfs_num[MAX] , dfs_low[MAX];
int dfs_parent[MAX];
int dfsNumberCounter;
int articulation_vertex[MAX];
int dfsRoot , RootChildren;
set<pi> Bridges;
int dis[MAX];

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            dfs_parent[v] = u;
            if(u == dfsRoot)
                ++RootChildren;
            articulationPointAndBridge(v);
            if(dfs_low[v] > dfs_num[u]){
                edge e(u , v);
                Bridges.erase(MP(min(u , v) , max(u ,v)));
            }
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
        else if(v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u] , dfs_num[v]);
        }
    }
}


bool escape = false;
int mx;
void dfs(int v , int timer){
    if(escape)
        return;
    mx = max(mx , dis[v]);
    for(auto node : adj[v]){

        if(articulation_vertex[node] && timer + 1 < dis[node]){
            escape = true;
            return;
        }
        if(timer + 1 < dis[node]){
            dfs(node , timer + 1);
        }

    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int t;
sc(t);
while(t--){
    RootChildren = 0;
    dfsNumberCounter = 0;
    memset(dfs_num , -1 , sizeof(dfs_num));
    memset(dfs_low , 0 , sizeof(dfs_low));
    memset(dfs_parent , 0 , sizeof(dfs_parent));
    memset(articulation_vertex , 0 , sizeof(articulation_vertex));
    escape = false;
    Bridges.clear();
    sc(n);sc(m);sc(A);sc(B);
    --A;
    --B;
    for(int i = 0 ;i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        --u;
        --v;
        Bridges.insert(MP(min(u,v) , max(u , v)));
        adj[u].pb(v);
        adj[v].pb(u);
    }
    RootChildren = 0;
    dfsRoot = A;
    articulationPointAndBridge(A);
    for(auto e : Bridges){
        articulation_vertex[e.first] = 1;
        articulation_vertex[e.second] = 1;
    }


    queue<int> q;
    q.push(B);
    mem(dis , 0);
    dis[B] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto node : adj[v]){
            if(!dis[node]){
                dis[node] = dis[v] + 1;
                q.push(node);
            }
        }
    }
    for(int i= 0 ; i < n ; ++i)
        --dis[i];



    mx = -1;
    dfs(A , 0);
    if(A == B){
        printf("0");
    }
    else if(escape || articulation_vertex[A]){
        printf("No");
    }
    else{
        printf("%d" , mx);
    }


    if(t)
        blank;

    for(int i = 0 ; i< n ; ++i)
        adj[i].clear();

}

return 0;
}
