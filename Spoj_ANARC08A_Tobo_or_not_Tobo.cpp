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
#define ENDSTR "0000000000"
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

string st;
string ans = "123456789";

unordered_map<string , int > top;
unordered_map<string , int > down;

string rot(string& t, int a, int b, int c, int d)
{
    string s(t);
    char x = s[a];
    s[a] = s[b];
    s[b] = s[c];
    s[c] = s[d];
    s[d] = x;
    return s;
}

string rotate(int d, int clockwise, string& t)
{
    switch (d) {
        case 0:
            return clockwise ? rot(t, 0, 3, 4, 1) : rot(t, 0, 1, 4, 3);
        case 1:
            return clockwise ? rot(t, 1, 4, 5, 2) : rot(t, 1, 2, 5, 4);
        case 2:
            return clockwise ? rot(t, 3, 6, 7, 4) : rot(t, 3, 4, 7, 6);
        case 3:
            return clockwise ? rot(t, 4, 7, 8, 5) : rot(t, 4, 5, 8, 7);
    }
    return t;
}

int BFS(int y , string &st , string &en , unordered_map<string , int> & vis){
    if(y < 0)
        return -1;
    if(!y){
        return st == en ? 0 : -1;
    }
    deque<pair<int,string> > q;
    q.pb(MP(0,st));
    vis.insert(MP(st , 0));
    while(!q.empty()){
        string cur = q.front().second;
        int dis = q.front().first;
        q.pop_front();
        if(cur == en){
            return dis;
        }
        if(dis >= y)
            continue;
        for(int i = 0 ; i < 4 ; ++i){
            for(int j = 0 ; j < 2 ; ++j){
                string temp = rotate(i , j , cur);
                if(vis.find(temp) == vis.end()){
                    q.pb(MP(dis + 1 , temp));
                    vis.insert(MP(temp , dis + 1));
                }
            }
        }
    }
    return -1;
}

int solve(int y , string &st){
    top.clear();
    down.clear();
    int res1 = BFS(y / 2, st , ans , top);
    if(res1 >= 0)
        return res1;
    int res2 = BFS(y - y / 2, ans , st , down);
    if(res2 >= 0)
        return res2;
    int res = 10;
    for(auto i : top){
        auto j = down.find(i.first);
        if(j != down.end()){
            int depth = j->second + i.second;
            if(depth < res && depth <= y){
                res = depth;
            }
        }
    }
    return (res == 10)?-1:res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
    int cases = 0;
    while(1){
        string s;
        cin>>s;
        if(s == ENDSTR){
            break;
        }
        int y = s[0]- '0';
        st = s.substr(1);
        int res = solve(y , st);
        printf("%d. %d\n" , ++cases , res);
    }


return 0;
}
