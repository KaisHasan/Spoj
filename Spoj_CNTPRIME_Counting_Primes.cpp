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

int a[MAX];
int tree[4*MAX];
int lazy[4*MAX];
int cnt[4*MAX];

void push(int p){
    if(!lazy[p])
        return;
    lazy[p*2] = 1;
    lazy[p*2+1] = 1;
    tree[p*2] = cnt[p*2]*(tree[p]>0);
    tree[p*2+1] = cnt[p*2+1]*(tree[p]>0);
    lazy[p] = 0;
}

void build(int p , int l , int r){
    if(l == r){
        tree[p] = a[l];
        cnt[p] = 1;
        return;
    }
    int md = (l+r)>>1;
    build(p * 2 , l , md);
    build(p * 2 + 1 , md + 1 , r);
    tree[p] = tree[p*2] + tree[p*2+1];
    cnt[p] = cnt[p*2] + cnt[p*2+1];
}

void update(int p , int l , int r , int st , int en , int val){
    if(l > en || r < st)
        return;
    if(l >= st && r <= en){
        tree[p] = cnt[p]*val;
        lazy[p] = 1;
        return;
    }
    push(p);

    int md = (l + r)>>1;
    update(p * 2 , l , md , st , en , val);
    update(p * 2 + 1, md + 1 , r , st , en , val);
    tree[p] = tree[p*2] + tree[p*2+1];
}

int qwr(int p , int l , int r , int st , int en){
    if(l > en || r < st)
        return 0;
    if(l >= st && r <= en){
        return tree[p];
    }
    push(p);

    int md = (l + r)>>1;
    return qwr(p * 2 , l , md , st , en) + qwr(p * 2 + 1 , md + 1 , r , st , en);
}


//seive
// O(n log log n)
ll SIZE;
bitset<2000010> isprime;
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(ll i = 2 ; i * i <= SIZE ; ++i){
        if(isprime[i]){
            for(ll j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
        }
    }
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    seive(1000010);
    while(t--){
        int n , q;
        sc(n);sc(q);
        for(int i = 0 ; i < n ; ++i){
            sc(a[i]);
            a[i] = isprime[a[i]];
        }
        mem(lazy, 0);
        mem(cnt, 0);
        build(1 , 0 , n - 1);
        printf("Case %d:\n" , ++cases);
        while(q--){
            int c;
            sc(c);
            if(c){
                int st , en;
                sc(st);sc(en);
                --st;--en;
                int res = qwr(1 , 0 , n - 1 , st , en);
                printf("%d\n" , res);
            }
            else{
                int st ,en, val;
                sc(st);sc(en);sc(val);
                --st;--en;
                val = isprime[val];
                update(1 , 0 , n - 1 , st , en , val);
            }
        }
    }



return 0;
}
