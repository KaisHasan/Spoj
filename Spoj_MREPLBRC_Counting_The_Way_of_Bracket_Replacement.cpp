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
const int MOD = 100000;
const double PI = acos(-1.0);
const double eps = 1e-7;

string s;
int n;

int f(char a , char b){
    if(a == ']' || a == ')' || a == '}')
        return 0;
    if(b == '[' || b == '(' || b == '{')
        return 0;
    if(a == '?' && b == '?')
        return 3;
    if(a == '?' || b == '?')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    return 0;
}
ll dp[222][222];
int flg;
ll solve(int l , int r){
    if(l == r)
        return 0;
    if(l > r)
        return 1;
    if(l + 1 == r){
        return (f(s[l] , s[r]));
    }
    ll &res = dp[l][r];
    if(res != -1)
        return res;
    res = 0;
    for(int i = l + 1 ; i <= r ; i += 2){
        if(f(s[l] , s[i]))
            res = (res + (solve(l + 1 , i - 1) * solve(i + 1 , r) * f(s[l] , s[i])));
        if(res >= 100000){
            flg = 1;
            res %= MOD;
        }
    }
    return res;
}


int main(){

    sc(n);
    if(!n){
        printf("1");
        return 0;
    }
    cin>>s;
    flg = 0;
    mem(dp , -1);
    int ans = solve(0 , n - 1);
    string res = to_string(ans);
    if(flg){
        while((int)res.size() < 5)
            res = '0' + res;
    }
    cout<<res;
return 0;
}
