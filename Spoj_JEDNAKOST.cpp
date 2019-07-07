#include<iostream>
#include<string>
#include<algorithm>
#include<ctype.h>
#include<cstring>
#include<vector>

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
//const double PI = acos(-1.0);
const double eps = 1e-7;

int dp[MAX][5*MAX];
int n;
string s;
int m;
int loc;
int solve(int id , int sum){
    if(id == n){
//        printf("%d\n" , sum);
        if(sum == m)
            return 0;
        return inf;
    }
    if(sum > m)
        return inf;
    int &res = dp[id][sum];
    if(res != -1)
        return res;
    res = inf;
    string temp = "";
    int cnt = 0;
    if(id == loc){
        res = min(res , 1 + solve(n , sum));
        return res;
    }
    for(int i = id ; i < n && cnt < 6; ++i){
        temp += s[i];
        if(cnt || s[i] != '0')
            ++cnt;
        else
            continue;
        res = min(res, 1 + solve(i + 1 , sum + stoi(temp)));
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    string st;
    cin>>st;
    int pos = -1;
    for(int i = 0 ; i < (int)st.size() ; ++i){
        if(st[i] == '='){
            pos = i;
            break;
        }
    }
    s = st.substr(0 , pos);
    m = stoi(st.substr(pos + 1));
    mem(dp , -1);
    n = s.size();
    loc = -1;
    for(int i = n - 1; i >= 0 && s[i] == '0'; --i){
        loc = i;
    }
    int res = solve(0 , 0);
    cout<<res-1;



return 0;
}
