// Wrote by MenYifan on 2015-08-16 11:34:20
// Exe.Time 16ms Exe.Memory 4576K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define vset(a,val) memset(a,val,sizeof(a))
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
#define Vmax 999
struct Prim{
    int n;//n???
    int s;//?? ???
    int weight;//????
    int mp[Vmax][Vmax];
    int dis[Vmax];
    bool vis[Vmax];
    int pre[Vmax];//????
    
    void init(int Vsz,int source=1){
        n=Vsz;
        weight=0;
        for(int i=0;i<=n;i++){
            dis[i]=INF;
            vis[i]=false;
        }
        dis[source]=0;
    }
    
    //1~n?????
    void adde(int u,int v,int w){
        mp[u][v]=w;
        mp[v][u]=w;
    }
    
    bool prim(){
        int cnt=0;
        for(int i=1;i<=n;i++){
            int pos=0;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&dis[j]<dis[pos])
                    pos=j;
            }
            vis[pos]=true;cnt++;
            weight+=dis[pos];
            for(int j=1;j<=n;j++){
                if(!vis[j]&&mp[pos][j]<dis[j]){
                    dis[j]=mp[pos][j];
                    pre[j]=pos;
                }
            }
        }
        if(cnt==n) return true;
        else return false;
    }
};
int main(){
    int n,tmp;
    while (sf(n)!=EOF) {
        Prim p;
        p.init(n);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                sf(tmp);
                p.adde(i, j, tmp);
            }
        }
        if (p.prim()) {
            cout<<p.weight<<endl;
        }
    }
}