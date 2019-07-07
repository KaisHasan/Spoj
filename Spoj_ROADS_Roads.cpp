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

int n , m , k;
vector<pair<int , pi> > adj[101];
int dist[101][10001];

int Dijkstra(int st , int en){
    for(int i = 0 ; i <= n ; ++i)
        fill(dist[i] , dist[i] + k + 1 , inf);
    dist[st][k] = 0;
    priority_queue<pair<int , pi> , vector<pair<int , pi> > , greater< pair<int , pi> > > pq;
    pq.push(MP(0 , MP(st , k)));
    while(!pq.empty()){
        int u = pq.top().second.first;
        int rem = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();
        if(w > dist[u][rem])
            continue;
        for(auto it : adj[u]){
            int v = it.first;
            int l = it.second.first;
            int t = it.second.second;
            if(t > rem)
                continue;
            if(w + l < dist[v][rem-t]){
                dist[v][rem-t] = w + l;
                pq.push(MP(w + l , MP(v , rem - t)));
            }
        }
    }
    int res =  *min_element(dist[en] , dist[en] + k + 1);
    if(res == inf)
        res = -1;
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int c;
    sc(c);
    while(c--){
        sc(k);sc(n);sc(m);
        for(int i = 0 ; i < m ; ++i){
            int u ,v , l , t;
            sc(u);sc(v);sc(l);sc(t);
            adj[u].pb(MP(v , MP(l,t)));
        }
        int res = Dijkstra(1 , n);
        printf("%d\n" , res);
        for(int i = 0 ; i <= n ; ++i)
            adj[i].clear();
    }



return 0;
}
