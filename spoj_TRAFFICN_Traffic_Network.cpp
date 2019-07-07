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
const int MAX = 1e4+55;
const ll inf = 1e16+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;


ll dis[MAX] , rdis[MAX];
vector<pll> adj[2][MAX];

void Dijkstra(ll dist[] , int id , int n , int s){
    fill(dist , dist + n + 1 , inf);
    priority_queue< pll , vector<pll> , greater<pll> > pq;
    pq.push(MP(0,s));
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        ll w = pq.top().first;
        pq.pop();
        if(w > dist[u])
            continue;
        for(auto v : adj[id][u]){
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(MP(dist[v.first] , v.first));
            }
        }
    }
}

int main(){

    int t;
    sc(t);
    while(t--){
        int n , m , k , s , e;
        sc(n);sc(m);sc(k);sc(s);sc(e);
        fill(dis , dis + n + 1 , inf);
        while(m--){
            int u , v , w;
            sc(u);sc(v);sc(w);
            adj[0][u].pb(MP(v,w));
            adj[1][v].pb(MP(u,w));
        }
        Dijkstra(dis , 0 , n , s);
        Dijkstra(rdis , 1 , n , e);
        ll ans = dis[e];
        while(k--){
            int u , v , w;
            sc(u);sc(v);sc(w);
            ans = min(ans , dis[u] + w + rdis[v]);
            ans = min(ans , dis[v] + w + rdis[u]);
        }
        if(ans == inf){
            printf("-1");
        }
        else{
            printf("%lld" , ans);
        }
        blank;
        for(int i = 0 ; i <= n ; ++i){
            adj[0][i].clear();
            adj[1][i].clear();
        }
    }


return 0;
}
