// Wrote by MenYifan on 2015-07-24 16:00:48
// Exe.Time 873ms Exe.Memory 3140K
//
//  20150724c.cpp
//  Cfiles
//
//  Created by ??? on 15/7/24.
//  Copyright (c) 2015? ???. All rights reserved.
//

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
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define PI acos(-1)
#define bug         pf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
#define maxn 10005
int main(){
    ll c,n,sum,i,s,e;
    while (scanf("%lld%lld",&c,&n),c+n) {
        ll a[100050]={};
        ll st[100050]={};
        for (int i=0; i<n; i++) {
            scanf("%lld",a+i);
        }
        sum=0;
        for (int i=0; i<n; i++) {
            sum=(sum+a[i]%c)%c;
            if (sum==0) {
                s=0;
                e=i;
            }
            else if (st[sum]){
                s=st[sum]+1;
                e=i;
            }
            else
                st[sum]=i;
        }
        
        
        for (i=s; i<=e; i++) {
            printf("%lld",i+1);
            if (i!=e) {
                printf(" ");
            }
            else
                printf("\n");
        }
    }
}