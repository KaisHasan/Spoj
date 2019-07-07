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
char grid[33][33];

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};

bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 'X' && grid[x][y] != 'S' ;
}
int dist[33][33];
int Dijkstra(pi st , pi en){
    for(int i = 0 ; i < 33 ; ++i){
        fill(dist[i] , dist[i] + 33 , inf);
    }
    dist[st.first][st.second] = 0;
    priority_queue<pair<int , pi> , vector<pair<int , pi> > , greater<pair<int , pi> > > pq;
    pq.push(MP(0 , st));
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();
        if(w > dist[x][y])
            continue;
        for(int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx , ny)){
                int cost = 0;
                if(isdigit(grid[nx][ny]))
                    cost = grid[nx][ny] - '0';
                if(cost + w < dist[nx][ny]){
                    dist[nx][ny] = cost + w;
                    pq.push(MP(dist[nx][ny] , MP(nx,ny)));
                }
            }
        }
    }
    return dist[en.first][en.second];
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        sc(n);sc(m);
        if(m + n == 0)
            break;
        swap(n,m);
        pi st , en;
        for(int i = 0 ; i < n ; ++i){
            string s;cin>>s;
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = s[j];
                if(s[j] == 'S'){
                    st.first = i;
                    st.second = j;
                }
                else if(s[j] == 'D'){
                    en.first = i;
                    en.second = j;
                }
            }
        }

        int res = Dijkstra(st , en);
        printf("%d\n" , res);

    }




return 0;
}
