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

vector<int> adj[MAX];
int dis[MAX];
int n;

pi BFS(int st){
    mem(dis , 0);
    queue<int> q;
    q.push(st);
    dis[st] = 1;
    int mx = -1;
    int res = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(dis[v] > mx){
            mx = dis[v];
            res = v;
        }
        for(auto node : adj[v]){
            if(!dis[node]){
                dis[node] = dis[v] + 1;
                q.push(node);
            }
        }
    }
    return MP(mx , res);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    sc(n);
    for(int i = 0 ; i < n - 1; ++i){
        int x , y;
        sc(x);sc(y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int st = BFS(1).second;
    int res = BFS(st).first;
    printf("%d" , res - 1);


return 0;
}
