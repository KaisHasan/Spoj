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

/*
    lst ;
    0   1   2   3
    N   S   ->  <-
*/
struct node{
    int x , y;
    node(){}
    node(int a, int b){
        x = a;
        y = b;

    }
    node(const node& temp){
        x = temp.x;
        y = temp.y;

    }
};
int n , m;
char grid[102][102];
int dx[] = {0 , 0, 1 , -1};
int dy[] = {-1 , -1 , 0, 0};
int dis[102][102];
queue<node> q;
bool valid(int x , int y){
    return x >=0 && y >= 0 && x < n && y < m   && grid[x][y] != '*';
}
void process(int x , int y , int cur , int lst){
    if(cur != v.lst && v.lst != -1){
        v.cnt++;
    }
    v.lst = cur;
    q.push(node(x , y , v.lst , v.cnt));
    vis[x][y]++;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(m);sc(n);
    vector<pi> c;
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid[i][j] = s[j];
            if(grid[i][j] == 'C'){
                c.pb(MP(i , j));
            }
        }
    }
    if(c.size() <= 1){
        printf("0");
        return 0;
    }

    q.push(node(c[0].first , c[0].second , -1 , 0));
    vis[c[0].first][c[0].second] = 1;
    while(!q.empty()){
        node v = q.front();
        q.pop();
        if(v.x == c[1].first && v.y == c[1].second){
            printf("%d" , v.cnt);
            return 0;
        }
        for(int i = 0 ; i < 4 ; ++i){
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            if(valid(nx , ny)){
                int cur = i;
                process(nx , ny , cur , v);
            }
        }
    }





return 0;
}
