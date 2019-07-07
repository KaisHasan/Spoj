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
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , m;
int csWest[505][505] , csNorth[505][505];
int dp[505][505][2];
int solve(int row = 0, int lst = 0, int flg = 0){
    if(row == n)
        return 0;
    int &res = dp[row][lst][flg];
    if(res != -1)
        return res;
    res = 0;
    if(!flg)
        res = max(res , solve(row + 1 , lst , 0) + csNorth[row][m-1]);
    for(int i = lst ; i < m ; ++i){
        res = max(res , solve(row + 1 , i , 1) + csWest[row][i] + (csNorth[row][m-1] - csNorth[row][i]));
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        sc(n);sc(m);
        if(n + m == 0)
            break;
        for(int i = 0 ; i < n ; ++i){
            int sum = 0;
            for(int j = 0 ; j < m ; ++j){
                int x;sc(x);
                sum += x;
                csWest[i][j] = sum;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            int sum = 0;
            for(int j = 0 ; j < m ; ++j){
                int x;sc(x);
                sum += x;
                csNorth[i][j] = sum;
            }
        }
        mem(dp,-1);
        int ans = solve();
        printf("%d\n" , ans);
    }



return 0;
}
