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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const ll inf = 1e12+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ll dis[55][55];



int main(){

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        int n;
        sc(n);
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                scl(dis[i][j]);
            }
        }
        for(int k = 1 ; k <= n ; ++k){
            for(int i = 1 ; i <= n ; ++i){
                for(int j = 1 ; j <= n ; ++j){
                    dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
                }
            }
        }
        int r;
        sc(r);
        int tot = 0;
        while(r--){
            int u ,v;
            sc(u);sc(v);
            tot += dis[u][v];
        }
        printf("Case #%d: %d\n" , ++cases , tot);
    }


return 0;
}
