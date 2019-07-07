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
#define mem(a , v)  memset(a , v , sizeof(a))
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


/*
    1   2   3   4
    b   y   r   g
*/
struct node{
    int x , y , keys , dis;
    node(){}
    node(int a , int b, int c , int d){
        x = a;
        y = b;
        keys = c;
        dis = d;
    }
};

int n , m;
char grid[102][102];
int dis[102][102];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
string color = "byrg";
int vis[102][102][33];
bool valid(int x , int y , int key){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#' && vis[x][y][key] == 0
        && (grid[x][y] != 'B' || (key&(1<<0)))
        && (grid[x][y] != 'Y' || (key&(1<<1)))
        && (grid[x][y] != 'R' || (key&(1<<2)))
        && (grid[x][y] != 'G' || (key&(1<<3)));
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int f = 0;
while(1){
    sc(n);sc(m);
    if(!n && !m)
        break;
    if(f)
        blank;
    f= 1;
    pi st;
    for(int i = 0 ;i < n ; ++i){
        string s;
        cin>>s;
        for(int j = 0 ; j < m ; ++j){
            grid[i][j] = s[j];
            if(grid[i][j] == '*')
                st = MP(i , j);
        }
    }
    mem(dis , 0);
    mem(vis , 0);

    queue<node> q;
    int ans = inf;
    q.push(node(st.first , st.second , 0 , 0));
    while(!q.empty()){
        node v = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            int keys = v.keys;
            if(valid(nx , ny , keys)){
                for(int j = 0 ; j < 4 ; ++j){
                    if(grid[nx][ny] == color[j]){
                        keys |= (1<<j);
                    }
                }
                if(grid[nx][ny] == 'X')
                    ans = min(ans , v.dis + 1);
                else{
                    vis[nx][ny][v.keys]++;
                    q.push(node(nx , ny , keys , v.dis + 1));
                }
            }
        }
    }

    if(ans == inf)
        printf("The poor student is trapped!");
    else
        printf("Escape possible in %d steps." , ans);

}



return 0;
}
