// Wrote by MenYifan on 2016-09-16 11:16:54
// Exe.Time 436ms Exe.Memory 1848K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
ll a[maxn];
struct node{
    ll val,cnt;
    bool operator < (const node &x)const{
        return val < x.val;
    }
};
vector<node>v;
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        ll op,cnt=0,tmp;
        for (int i = 1; i<=n; i++) {
            scanf("%lld",&op);
            if (op == 1) {
                scanf("%lld",&tmp);
                a[++cnt] = tmp;
            }
            else{
                ll l,r,k;
                scanf("%lld%lld%lld",&l,&r,&k);
                v.clear();
                for (ll i = cnt; i>=1; i--) {
                    tmp = (r+1)/2 - l / 2;
                    v.push_back((node){a[i], tmp});
                    r /= 2;
                    l = (l+1)/2;
                    if (r < l) break;
                }
                sort(v.begin(), v.end());
                for (int i = 0; i<v.size(); i++) {
                    k -= v[i].cnt;
                    if (k <= 0) {
                        printf("%lld\n",v[i].val);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}