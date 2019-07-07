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
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const ll inf = 1e17+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n;
ll a[MAX];
ll c[MAX];
ll f(ll d){
    ll cost = 0;
    for(int i = 0 ; i < n ; ++i){
        cost += abs(a[i] - d) * c[i];
    }
    return cost;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        sc(n);
        for(int i = 0 ; i < n ; ++i)
            scl(a[i]);
        for(int i  = 0 ; i < n; ++i)
            scl(c[i]);
        ll st = 0  , en = 11000;
        while (en - st > 1){
            int mid = (en + st)>>1;
            if (f(mid) < f(mid + 1))
                 en = mid;
            else
                 st = mid;
        }
        cout<<f(st + 1);
        if(t)
            blank;
    }



return 0;
}
