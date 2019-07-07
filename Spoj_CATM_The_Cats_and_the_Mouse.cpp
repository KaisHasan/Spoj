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
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
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

int n , m;
int k;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    sc(k);
    for(int i = 0 ; i < k ; ++i){
        int x , y;
        sc(x);sc(y);
        int c1x , c1y;
        sc(c1x);sc(c1y);
        int c2x , c2y;
        sc(c2x);sc(c2y);
        int d1 = abs(x - n);
        int cd1 = abs(c1x - n) + abs(c1y - y);
        int cd2 = abs(c2x - n) + abs(c2y - y);
        if(cd1 > d1 && cd2 > d1){
            cout<<"YES\n";
            continue;
        }
        d1 = abs(x - 0);
        cd1 = abs(c1x - 0) + abs(c1y - y);
        cd2 = abs(c2x - 0) + abs(c2y - y);
        if(cd1 > d1 && cd2 > d1){
            cout<<"YES\n";
            continue;
        }
        ///////////////
        d1 = abs(y - 0);
        cd1 = abs(c1y - 0) + abs(c1x - x);
        cd2 = abs(c2y - 0) + abs(c2x - x);
        if(cd1 > d1 && cd2 > d1){
            cout<<"YES\n";
            continue;
        }
        d1 = abs(y - m);
        cd1 = abs(c1y - m) + abs(c1x - x);
        cd2 = abs(c2y - m) + abs(c2x - x);
        if(cd1 > d1 && cd2 > d1){
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }



return 0;
}
