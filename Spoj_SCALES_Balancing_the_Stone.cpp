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
const int MAX = 1e6+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n, l , d;
int a[MAX];
int dp[MAX][2];

int solve(int id , int carry){
    if(id == n)
        return !carry;
    int &res = dp[id][carry];
    if(res != -1)
        return res%d;
    res = 0;
    int bit = a[id] + carry;
    if(bit == 1){
        res = (res + solve(id + 1 , 1)) % d;
        res = (res + solve(id + 1 , 0))%d;
    }
    else{
        res = (res + solve(id + 1 , bit>>1))%d;
    }
    return res%d;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int t;
    sc(t);
    while(t--){
        sc(n);sc(l);sc(d);
        string s;
        cin>>s;
        reverse(all(s));
        for(int i = 0 ; i < l ; ++i)
            a[i] = s[i] - '0';
        for(int i = l ; i < n ; ++i)
            a[i] = 0;
        mem(dp,-1);
        int ans = solve(0 , 0)%d;
        printf("%d\n" , ans);
    }




return 0;
}
