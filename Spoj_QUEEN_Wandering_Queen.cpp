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

int n , m;
int vis[1002][1002][8];
int dis[1002][1002];
char grid[1002][1002];
int dx[] = {-1 , 1 , 0 , 0 , -1 , -1 , 1 , 1};
int dy[] = {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1};
bool valid(int x, int y , int d){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 'X' && vis[x][y][d] == 0;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        sc(n);sc(m);
        pi st , en;
        mem(dis , 0);
        mem(vis , 0);
        for(int i = 0 ; i < n ; ++i){
            string s;cin>>s;
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = s[j];
                if(s[j] == 'S'){
                    st = MP(i,j);
                }
                if(s[j] == 'F'){
                    en = MP(i,j);
                }
            }
        }
        queue<pi> q;
        q.push(st);
        dis[st.first][st.second] = 1;
        for(int i = 0 ; i < 8 ; ++i)
            vis[st.first][st.second][i] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(x == en.first && y == en.second)
                break;
            q.pop();
            for(int i = 0 ; i < 8 ; ++i){
                for(int j = 1 ; j <= m ; ++j){
                    int nx = x + j * dx[i];
                    int ny = y + j * dy[i];
                    if(valid(nx , ny , i)){
                        if(dis[nx][ny] != 0){
                            vis[nx][ny][i] = 1;
                            continue;
                        }
                        q.push(MP(nx,ny));
                        dis[nx][ny] = dis[x][y] + 1;
                        vis[nx][ny][i] = 1;
                    }
                    else
                        break;
                }
            }
        }
        while(!q.empty())
            q.pop();
        if(dis[en.first][en.second] == 0)
            printf("-1\n");
        else{
            printf("%d\n" , dis[en.first][en.second] - 1);
        }
    }



return 0;
}
