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
#define scl(a) scanf("%I64d",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

ll lcm( ll a,ll b)
{
    ll k = __gcd(a,b);
    a /= k;
    return a * b;
}
vector<ll> v(5);
ll x;
ll inc_exc(int id = 0 , ll d = 1, ll sign = 1){
    if(id == 5){
        return (sign * x)/d;
    }
    return inc_exc(id + 1 , d , sign) + inc_exc(id + 1 ,lcm(d , v[id]) , sign * -1);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
    ll n, m , a ,d;
    int t;
    sc(t);
    while(t--){
        cin>>n>>m>>a>>d;
        for(int i = 0 ; i < 5 ; ++i){
            v[i] = a + i * d;
        }
        x = m;
        ll resm = inc_exc();
        x = n - 1;
        ll resn = inc_exc();
        cout<<resm - resn<<endl;

    }
return 0;
}
