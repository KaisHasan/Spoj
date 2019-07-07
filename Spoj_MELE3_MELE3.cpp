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

int n , m;

pi get_pos(int st , int w , int en){
    int tot = w + st;
    if(tot <= en)
        return MP(tot , 0);
    int r = w/abs(en-st);
    int res;
    if(r & 1)
        res =  en - (w%abs(en-st));
    else
        res  = w%(en-st) + st;
    return MP(res , r & 1);
}

int get_d(int cur , int nxt , int en , int dir , int st){
    if(!dir){
        if(nxt >= cur)
            return nxt - cur;
        return 2*en - cur - nxt;
    }
    else{
        if(nxt <= cur)
            return cur - nxt;
        return -2*st + cur + nxt;
    }
}

vpi adj[MAX];
int dist[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(MP(v,1));
        adj[v].pb(MP(u,-1));
    }
    for(int i = 1 ; i <= n ; ++i)
        dist[i] = inf;
    dist[1] = 0;
    priority_queue<pi , vpi , greater<pi> > pq;
    pq.push(MP(0,1));
    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(w > dist[u])
            continue;
        for(auto it : adj[u]){
            int v = it.first;
            int c = it.second;
            int st = u , en = v;
            if(c == -1)
                swap(st , en);
            pi res = get_pos(st , w , en);
            int pos = res.first;
            int dir = res.second;
            int d = get_d(pos , u, en , dir , st);
            int cost = d + abs(v - u);
            if(cost + w < dist[v]){
                dist[v] = cost + w;
                pq.push(MP(dist[v] , v));
            }
        }
    }
    printf("%d" , dist[n]*5);



return 0;
}
