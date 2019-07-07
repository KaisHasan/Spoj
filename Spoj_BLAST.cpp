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
const int MAX = 2019;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

string s , t;
int n1 , n2 , k;
int dp[MAX][MAX];
int solve(int i , int j){
    if(i == n1){
        return (abs(n2-j)*k);
    }
    if(j == n2){
        return (abs(n1-i)*k);
    }
    int &res = dp[i][j];
    if(res != -1)
        return res;
    res = inf;
    res = min(res , solve(i + 1 , j) + k);
    res = min(res , solve(i , j + 1) + k);
    res = min(res , solve(i + 1, j + 1) + abs(s[i] - t[j]));
    return res;
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    cin>>s>>t;
    n1 = s.size();
    n2 = t.size();
    sc(k);
    mem(dp , -1);
    int res = solve(0,0);
    printf("%d" , res);


return 0;
}
