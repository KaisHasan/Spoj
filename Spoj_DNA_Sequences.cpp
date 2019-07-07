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
const int MAX = 1005;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int dp[MAX][MAX];
int cnt[MAX][MAX];
int n1 , n2;
int k;
string s ,t;



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        sc(k);
        if(!k)
            break;

        cin>>s>>t;
        n1 = s.size();
        n2 = t.size();
        for(int i = 0 ; i < MAX ; ++i)
            dp[i][0] = dp[0][i] = 0;
        for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n2 ; ++j){
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                if(s[i-1] == t[j-1])
                    cnt[i][j] = cnt[i-1][j-1] + 1;
                else
                    cnt[i][j] = 0;
                if(cnt[i][j] >= k){
                    for(int z = k ; z <= cnt[i][j] ; ++z)
                        dp[i][j] = max(dp[i][j] , dp[i-z][j-z] + z);
                }
            }
        }
        int res = dp[n1][n2];
        printf("%d\n" , res);
    }



return 0;
}
