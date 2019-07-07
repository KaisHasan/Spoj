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

int len;
ll dp1[10][2][2];
ll dp2[10][2][2];
int num;
ll D(int i , int isFull , int isLeading , string &s){
    if(i == len){
        return !isLeading;
    }
    ll &res = dp1[i][isFull][isLeading];
    if(res != -1)
        return res;
    res = 0;
    for(int j = 0 ; j < 10 ; ++j){
        if(isFull && j > s[i] - '0')
            break;
        bool F = isFull && (j == s[i]-'0');
        bool L = isLeading && (j == 0);
        res += D(i + 1 , F , L , s);
    }
    return res;
}

ll solve(int i , int isFull , int isLeading , int x , string& s){
    if(i == len)
        return 0;
    ll &res = dp2[i][isFull][isLeading];
    if(res != -1)
        return res;
    res = 0;
    for(int j = 0 ; j < 10 ; ++j){
        if(isFull && (j>s[i]-'0'))
            break;
        bool F = isFull && (j==s[i]-'0');
        bool L = isLeading && (!j);
        res += solve(i + 1 , F ,L , x , s);
        if(isLeading && !j)
            continue;
        if(j == x){
            res += D(i + 1 , F , L , s);
        }
    }
    return res;
}





int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    while(1){
        int a , b;
        sc(a);sc(b);
        if(a > b)
            swap(a , b);
        if(a + b == 0)
            break;
        --a;
        string s1 = to_string(a);
        string s2 = to_string(b);
        for(int i = 0; i < 10 ; ++i){
            mem(dp1 , -1);
            mem(dp2 , -1);
            len = s2.size();
            ll res1 = solve(0 , 1 , 1 , i , s2);
            mem(dp1 , -1);
            mem(dp2 , -1);
            len = s1.size();
            ll res2 = solve(0 , 1 , 1 , i , s1);
            ll res = res1 - res2;
            printf("%lld" , res);
            if(i != 9)
                printf(" ");
        }
        blank;
    }



return 0;
}
