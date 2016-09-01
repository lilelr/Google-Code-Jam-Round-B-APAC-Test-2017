
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define LL long long
const LL mod=1e9+7;

long long  modExp(long long  a,long long  b,long long  n){
    long long  t,y;
    t = 1; y = a;
    while(b){
        if(b % 2) t = t * y % n;
        y = y * y % n;
        b >>= 1;
    }
//    printf("%lld\n",t);
    return t;
}

int main() {
//    modExp(2, 6, 63);
    
    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B APAC Test 2017/B-small-practice.in","r",stdin);
    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B APAC Test 2017/B-pratice.out","w",stdout);
    int T,t;
    cin>>T;
    t=1;
    LL N;
    LL A,B,K;
    LL ans;
//    cout<<mod<<endl;
    while (T--){
       
        cin>>A>>B>>N>>K;
        ans=0;
        for (LL i=1; i<=N; i++) {
            for(LL j=1;j<=N;j++){
                if(i!=j){
                    LL left = modExp(i, A, K);
                    LL right = modExp(j, B, K);
                    if ((left %K+right %K)%K == 0) {
                        ans = (ans+1)%mod;
                    }
                }
            }
        }
        
        printf("Case #%d: %lld\n",t++,ans);
    }
    return 0;
}
