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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int t;

set<pi> vis;
queue<pi> q;
void process(int a , int b){
    if(vis.find(MP(a , b)) == vis.end()){
        vis.insert(MP(a , b));
        q.push(MP(a , b));
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

sc(t);
while(t--){
    int a, b , c;
    sc(a);sc(b);sc(c);
    vis.clear();
    q.push(MP(0 , 0));
    vis.insert(MP(0,0));
    int res = -1;
    if(c % __gcd(a , b) == 0 && c <= max(a , b)){
        res = 0;
        bool f = false;
        while(!q.empty()){
            int sz= q.size();
            while(sz--){
                pi v = q.front();
                q.pop();
                if(v.first == c || v.second == c){
                    f = true;
                    break;
                }
                //fill first jug
                process(a , v.second);
                //fill second jug
                process(v.first , b);
                //empty first jug
                process(0 , v.second);
                //empty second jug
                process(v.first , 0);
                //from a to b
                int newB = min(b , v.first + v.second);
                int newA = v.first - (newB - v.second);
                process(newA , newB);
                //from a to b
                newA = min(a , v.first + v.second);
                newB = v.second - (newA - v.first);
                process(newA , newB);
            }
            if(f){
                printf("%d\n" , res);
                break;
            }
            ++res;
        }
    }
    if(res == -1)
        printf("%d\n" , res);
    while(!q.empty())
        q.pop();
}



return 0;
}
