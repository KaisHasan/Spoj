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

int c , n;
set < int > s;
pi a[MAX];
int col[5];
vi name;
int LIS(int n){
    s.clear();
    set < int > :: iterator it;
    for(int i = 0 ; i < n ; ++i){
        s.insert(name[i]);

        it = s.upper_bound(name[i]);

        if(it != s.end())
            s.erase(it);
    }
    return n - (int)s.size();
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    sc(c);sc(n);
    for(int i = 0 ; i < c * n ; ++i){
        int x , y;
        sc(x);sc(y);
        a[i] = MP(x,y);
    }
    vi v;
    for(int i = 1 ; i <= c ; ++i)
        v.pb(i);
    int ans = inf;
    do{
        int id = 0;
        for(auto i : v){
            col[i] = id++;
        }
        name.clear();
        for(int i = 0 ; i < c * n ; ++i){
            int pos = n * col[a[i].first] + (a[i].second - 1);
            name.pb(pos);
        }
        ans = min(ans , LIS(c * n));
    }while(next_permutation(all(v)));
    printf("%d" , ans);

return 0;
}
