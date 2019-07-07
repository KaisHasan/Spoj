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

struct node{
    int x , y , time;
    node(){}
    node(int a , int b , int c){
        x = a;
        y = b;
        time = c;
    }
    node(const node& temp){
        x = temp.x;
        y = temp.y;
        time = temp.time;
    }

};

int n , m;
int t;
bool toast[21][21][11];
int vis[21][21];
int dx[] = {-1 , 1,  0 , 0};
int dy[] = {0 , 0 , -1, 1 };
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && vis[x][y] < 100;
}
bool test(int x , int y , int k){
    return !(toast[x][y][k%t]);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int cases = 0;
while(1){
    sc(n);sc(m);sc(t);
    if(!n && !m && !t)
        break;
    if(cases)
        blank;
    ++cases;
    for(int i = 0; i < t ; ++i){
        for(int j = 0 ; j < n ; ++j){
            string s;cin>>s;
            for(int k = 0 ; k < m ; ++k){
                toast[j][k][i] = s[k] - '0';
            }
        }
    }
    mem(vis , 0);
    queue<node> q;
    q.push(node(0,0,0));
    bool f = false;
    while(!q.empty()){
        node v = q.front();
        q.pop();
        if(v.x == n - 1 && v.y == m - 1){
            printf("Case %d: Luke and Leia can escape in %d steps." ,cases , v.time);
            f = true;
            break;
        }
        if(valid(v.x , v.y) && test(v.x , v.y  , v.time + 1)){
            q.push(node(v.x , v.y , v.time + 1));
            vis[v.x][v.y]++;
        }
        for(int i = 0 ; i < 4 ; ++i){
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            int nTime = v.time + 1;
            if(valid(nx , ny ) && test(nx , ny , nTime)){
                q.push(node(nx , ny , nTime));
                vis[nx][ny]++;
            }
        }
    }
    if(!f){
        printf("Case %d: Luke and Leia cannot escape." , cases);
    }
    while(!q.empty())
        q.pop();
}



return 0;
}
