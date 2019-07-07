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
const int inf = 1e7+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n , m;
int id;
char grid[22][22];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
int vis[13][22][22];
pi dirts[13];
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 'x';
}
int dp[2250][13];
int solve(int rem , int lst){
    if(rem == (1<<id)-1){
        return 0;
    }
    int &res = dp[rem][lst];
    if(res != -1)
        return res;
    res = inf;
    for(int i = 0 ; i < id ; ++i){
        if(rem & (1<<i))
            continue;
        int nx = dirts[i].first;
        int ny = dirts[i].second;
        if(vis[lst][nx][ny] == -1)
            continue;
        res = min(res , solve(rem | (1<<i) , i) + vis[lst][nx][ny]);
    }
    return res;
}

void BFS(int x , int y , int id){
    queue<pi> q;
    q.push(MP(x ,y));
    vis[id][x][y] = 1;
    while(!q.empty()){
        pi v = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];
            if(valid(nx , ny) && vis[id][nx][ny] == 0){
                vis[id][nx][ny] = vis[id][v.first][v.second] + 1;
                q.push(MP(nx , ny));
            }
        }
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            vis[id][i][j]--;
        }
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        mem(dp , -1);
        sc(m);sc(n);
        if(!m && !n)
            break;
        id = 0;
        int x , y;
        for(int i = 0 ; i < n ; ++i){
            string s;cin>>s;
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = s[j];
                if(s[j] == '*'){
                    dirts[id++] = MP(i,j);
                }
                if(s[j] == 'o'){
                    x = i;
                    y = j;
                }
            }
        }
        mem(vis , 0);
        BFS(x , y , 11);
        for(int i = 0 ; i < id ; ++i){
            BFS(dirts[i].first , dirts[i].second , i);
        }

        int res = solve(0 , 11);
        if(res == inf)
            res = -1;
        printf("%d\n" , res);
    }



return 0;
}
