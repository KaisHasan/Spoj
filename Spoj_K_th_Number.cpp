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

vi tree[4*MAX];
int a[MAX];
int n;
void build(int p = 1 , int st = 0 , int en = n - 1){
    if(st == en){
        tree[p] = vi(1 , a[st]);
        return;
    }
    int md = (st+en)>>1;
    build(p*2 , st , md);
    build(p*2+1 , md + 1, en);
    merge(tree[p*2].begin() , tree[p*2].end() , tree[p*2+1].begin() ,tree[p*2+1].end() , back_inserter(tree[p]));
}

vi qwr(int p , int st , int en , int l ,int r){
    if(st > r || en < l)
        return vi();
    if(st >= l && en <= r)
        return tree[p];
    int md = (st+en)>>1;
    vi t1 = qwr(p*2 , st , md , l , r);
    vi t2 = qwr(p * 2 + 1 , md + 1 , en , l , r);
    vi t;
    merge(t1.begin() , t1.end() , t2.begin() , t2.end() , back_inserter(t));
    return t;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    int q;
    sc(q);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    build();
    while(q--){
        int l , r , k;
        sc(l);sc(r);sc(k);
        --l;--r;--k;
        vi v = qwr(1 , 0 , n - 1 , l , r);
//        pla;
//        for(auto i : v){
//            printf("%d " , i);
//        }
//        blank;
//        pla;
        printf("%d\n" , v[k]);
    }



return 0;
}
