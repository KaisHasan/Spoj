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

int cur[MAX] , nxt[MAX];
int tree[4*MAX];
map<string , int> code;

void push(int p){
    if(!tree[p])
        return;
    tree[p*2] += tree[p];
    tree[p*2+1] += tree[p];
    tree[p] = 0;
}

void update(int p , int l , int r , int st , int en, int val){
    if(l > en || r < st)
        return;
    if(l >= st && r <= en){
        tree[p] += val;
        return;
    }
    push(p);
    int md = (l + r)>>1;
    update(p * 2 , l , md , st , en , val);
    update(p * 2 + 1, md + 1 , r , st , en , val);
    tree[p] = 0;
}

int qwr(int p , int l , int r ,  int pos){
    if(l > pos || r < pos)
        return 0;
    if(l == r && l == pos)
        return tree[p];
    push(p);
    int md = (l+r)>>1;
    return qwr(p*2 , l , md , pos) + qwr(p * 2 + 1 , md + 1 , r , pos);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        code.clear();
        mem(tree , 0);
        for(int i = 0 ; i < n ; ++i){
            string s;
            cin>>s;
            code[s] = i + 1;
        }
        for(int i = 1 ; i <= n ; ++i){
            string s;cin>>s;
            nxt[i] = i;
            cur[i] = code[s];
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; ++i){
            int add = qwr(1 , 1 , n , cur[i]);
            update(1 , 1 , n , 1 , cur[i] - 1 , 1);
            cur[i] += add;
            ans += (cur[i] - nxt[i]);
        }
        printf("%d\n" , ans);
    }





return 0;
}
