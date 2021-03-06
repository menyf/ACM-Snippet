// Wrote by MenYifan on 2016-07-24 16:08:52
// Exe.Time 516ms Exe.Memory 1316K
#pragma comment(linker, "/STACK:10240000000,10240000000")///?????c++???g++???????????
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-8
#define INF 0x7fffffff
#define maxn 100005
#define PI acos(-1.0)
using namespace std;
typedef long long LL;
const int N = 40005;

int n , m , pre[N] ,rt[N], mcnt;
int dis[N];
bool vis[N];
struct edge
{
    int x , next;
} e[N << 1];

int dep[N] , f[17][N] , Lev , s[N];///1<<16 < N, f[j][i] ??i??2^j???

void dfs(int x , int fa)///????bfs??bfs??????????
{
    dep[x] = dep[fa] + 1;
    f[0][x] = fa , s[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
        if (y != fa)
        {
            dfs(y , x);
            s[x] += s[y];///??x?????
        }
    }
}
void bfs(int rt)///???????????????
{
    queue<int> q;
    q.push(rt);
    f[0][rt] = 0,dep[rt] = 1,vis[rt] = 1;
    while(!q.empty())
    {
        int fa = q.front();
        q.pop();
        for (int i = pre[fa] ; ~i ; i = e[i].next)
        {
            int x = e[i].x;
            if (!vis[x])
            {
                dep[x] = dep[fa] + 1;
                f[0][x] = fa ,vis[x] = 1;
                q.push(x);
            }
        }
    }
}
int LCA(int x , int y)
{
    if (dep[x] > dep[y]) swap(x , y);
    for (int i = Lev ; i >= 0 ; -- i)///?y??dep[y] - dep[x]???
        if (dep[y] - dep[x] >> i & 1)
            y = f[i][y];
    if (x == y) return y;
    for (int i = Lev ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y])
            x = f[i][x] , y = f[i][y];
    return f[0][x];
}
int get_kth_anc(int x , int k) ///?x??k???
{
    for (int i = 0 ; i <= Lev ; ++ i)
        if (k >> i & 1)
            x = f[i][x];
    return x;
}
void init()
{
    memset(pre , -1 , sizeof(pre));
    memset(rt,0,sizeof(rt));
    memset(dis, 0, sizeof(dis));
    mcnt = 0;
}
void addedge(int x,int y)
{
    e[mcnt].x = y,
    e[mcnt].next = pre[x],
    pre[x] = mcnt ++;
}

int main()
{
    int i , j , x , y , z,anc,m,u,v;
    char ch2[2],ch1[2];
    while (scanf("%d",&n)!=EOF) {
        init();
        for (int i=0; i<n; i++) {
            scanf("%d:(%d)",&u,&m);
            for (int i=0; i<m; i++) {
                scanf("%d",&v);
                addedge(u,v);
                addedge(v,u);
                rt[v]  =u;
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(rt[i]==0)
            {
                anc = i;
                break;
            }
        }
        dfs(anc , 0);
        for (j = 1 ; 1 << j < n ; ++ j)
            for (i = 1 ; i <= n ; ++ i)
                f[j][i] = f[j - 1][f[j - 1][i]];
        Lev = j - 1;
        int k;
        scanf("%d",&k);
        for (int i=0; i<k; i++) {
            scanf("%1s%d %d%1s",ch1,&x,&y,ch2);
            if (dep[x] < dep[y])
                swap(x , y);
            dis[LCA(x, y)]++;
        }
        
        for (int i=1; i<=n; i++) {
            if (dis[i]) {
                printf("%d:%d\n",i,dis[i]);
            }
        }
    }
    return 0;
}
