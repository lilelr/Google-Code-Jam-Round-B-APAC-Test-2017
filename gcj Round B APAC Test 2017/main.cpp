
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

int main() {
    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B APAC Test 2017/A-large-practice.in","r",stdin);
    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B APAC Test 2017/A-large-practice.out","w",stdout);
    int T,t;
    cin>>T;
    t=1;
    LL L,R;
    LL ans;
    while (T--){
        cin>>L;
        cin>>R;
        LL pairs = min(L,R);
        if (pairs==0) {
            ans=0;
        }else{
            ans=pairs*(pairs+1)/2;
        }
        printf("Case #%d: %lld\n",t++,ans);
    }
    return 0;
}
