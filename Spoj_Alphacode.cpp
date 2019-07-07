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
const int MAX = 5005;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

ull dp[MAX];
string s;
int n;
ull solve(int id){
    if(id == n)
        return 1;
    ull &res = dp[id];
    if(res != -1)
        return res;
    res = 0;
    if(s[id] == '0')
        return res;
    else if(id + 1 < n && s[id + 1] == '0'){
        res += solve(id + 2);
    }
    else{
        res += solve(id + 1);
        if(id != n - 1)
            if(s[id] == '1' || (s[id] == '2' && s[id+1] <= '6'))
                res += solve(id + 2);
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    while(1){
        mem(dp , -1);
        cin>>s;
        if(s == "0")
            break;
        n = s.size();
        ull res = solve(0);
        cout<<res<<endl;
    }
return 0;
}
