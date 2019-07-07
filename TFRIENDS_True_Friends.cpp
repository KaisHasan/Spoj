#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

vector<int> adj[MAX];
int vis[MAX];
vector<int> SCC;
int dfs_num[MAX] , dfs_low[MAX];
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
            if(u == v)
                break;
        }
    }
}


int main(){

int t;
sc(t);
while(t--){
    memset(vis , 0 , sizeof(vis));
    memset(dfs_num , -1 ,sizeof(dfs_num));
    memset(dfs_low , 0 , sizeof(dfs_low));
    dfsNumberCounter = numSCC = 0;
    SCC.clear();
    int n;
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < n ; ++j){
            if(s[j] == 'Y'){
                adj[i].pb(j);
            }
        }
    }
    for(int i = 0 ; i < n ; ++i){
        if(dfs_num[i] == -1){
            tarjanSCC(i);
        }
    }
    printf("%d" , numSCC);

    for(int i = 0 ; i < n ; ++i)
        adj[i].clear();
    if(t)
        blank;

}


return 0;
}
