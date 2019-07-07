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
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n ,m;
int grid[200][200];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int dist[200][200];
int valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && dist[x][y] == -1;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        sc(n);sc(m);
        for(int i = 0 ; i < n ; ++i){
            string s;cin>>s;
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = s[j] - '0';
            }
        }
        mem(dist , -1);
        queue<pi> q;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j]){
                    q.push(MP(i,j));
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(valid(nx,ny)){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(MP(nx,ny));
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            printf("%d" , dist[i][0]);
            for(int j =1 ; j < m ; ++j)
                printf(" %d" , dist[i][j]);
            blank;
        }

    }




return 0;
}
