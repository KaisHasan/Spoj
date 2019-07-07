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


vector<bool> isprime(100001,true);
map<string , int> dis;

void seive(){
     ll n = 100000;
     isprime[0] = isprime[1] = 0;
     for(int i = 2 ; i*i < n ; ++i){
        if(isprime[i]){
            for(int j = i * 2 ; j <= n ; j+=i){
                isprime[j] = 0;
            }
        }
     }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

int t;
sc(t);
seive();
while(t--){
    string s1 ,s2;
    cin>>s1>>s2;
    queue<string> q;
    while(!q.empty())
        q.pop();
    dis.clear();
    q.push(s1);
    dis[s1] = 0;
    while(!q.empty()){
        string v = q.front();
        q.pop();
        if(v == s2){
            printf("%d\n" , dis[s2]);
            break;
        }
        for(int i = 0 ; i < 4 ; ++i){
            for(int j = 0 ; j < 10 ; ++j){
                    if(i == 0 && j ==0)
                        continue;
                    string temp = v;
                    temp[i] = char('0' + j);
                    int x;
                    istringstream iss(temp);
                    iss>>x;
                    if(isprime[x] && dis.find(temp) == dis.end()){
                        q.push(temp);
                        dis[temp] = dis[v] + 1;
                    }
            }
        }
    }

}



return 0;
}
