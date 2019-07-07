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
vector<pi> res;
int inDegree[MAX];
int edges[1002][1002];
int n , m;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

sc(n);sc(m);
for(int i = 0 ; i < m ; ++i){
    int u , v;
    sc(u);sc(v);
    adj[u].pb(v);
    inDegree[v]++;
}

queue<int> q;
vector<int> st;
for(int i = 1 ; i <= n ; ++i){
    if(inDegree[i] == 0)
        st.pb(i);
}
for(auto node : st)
    q.push(node);

while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto v : adj[u]){
        inDegree[v]--;
        if(!inDegree[v]){
            res.pb(MP(u , v));
            edges[u][v] = 1;
            q.push(v);
        }
    }
}

printf("%d\n" , res.size());
for(auto edge : res){
    printf("%d %d\n" , edge.first , edge.second);
}



return 0;
}
