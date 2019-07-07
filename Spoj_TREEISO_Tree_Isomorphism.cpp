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
int indegree[MAX];
int n;
string getNodeCanoincalForm(int v, vector< vector<string> > &subCan)    // we could use hashing for a better performance
{
    string nodeRep = "(";
    sort( all(subCan[v]) );
    for(int i = 0 ; i < subCan[v].size() ; ++i)
        nodeRep += subCan[v][i];
    nodeRep += ")";

    return nodeRep;
}

/*
 * Tree shrinking algorithm. Each time leaves shrink toward their parents.
 */
string treeCanoincalForm()  // assumes tree not forest
{

    // Prepare level one nodes: the leaves
    queue<int> LeafNodes;
    vector<int> deg(n, -1);
    int remNodes = n;
    for(int i = 0 ; i < n ; ++i){
        if(adj[i].size() <= 1)
            LeafNodes.push(i);
        else
            deg[i] = adj[i].size();
    }
    vector< vector<string> > subCan(n);

    while(remNodes > 2)  // bfs-like
    {
        int sz = LeafNodes.size();
        while(sz--) // level by level
        {
            int v = LeafNodes.front();          LeafNodes.pop();
            string nodeRep = getNodeCanoincalForm(v, subCan);
            for(int j = 0 ; j < adj[v].size() ; ++j){
                int to = adj[v][j];
                subCan[to].pb(nodeRep);
                if(--deg[to] == 1)
                    LeafNodes.push(to);
            }
            --remNodes;
        }
    }
    // what remains are tree centers
    int v1 = LeafNodes.front();         LeafNodes.pop();
    int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();

    string str1 = getNodeCanoincalForm(v1, subCan);
    string str2 = v2 == -1? "" : getNodeCanoincalForm(v2, subCan);

    if(v2 == -1)    // only 1 node
        return str1;

    // 2 nodes. try 2nd as child of first and reverse
    subCan[v1].pb(str2);
    subCan[v2].pb(str1);

    return min(getNodeCanoincalForm(v1, subCan), getNodeCanoincalForm(v2, subCan));
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
while(t--){
    sc(n);
    for(int i = 0 ; i < n - 1 ; ++i)
    {
        int x , y;
        sc(x);sc(y);
        --x;--y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    string res1 = treeCanoincalForm();
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear();
    for(int i = 0 ; i < n - 1 ; ++i)
    {
        int x , y;
        sc(x);sc(y);
        --x;--y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    string res2 = treeCanoincalForm();
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear();
    if(res1 == res2)
        printf("YES\n");
    else
        printf("NO\n");

}



return 0;
}
