//// http://blog.csdn.net/fcxxzux/article/details/52346364
//#include <algorithm>
//#include <cmath>
//#include <cstdio>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//#include <vector>
//using namespace std;
//#define LL long long
//const LL mod = 1e9 + 7;
//
//LL acnt[100005];
//LL bcnt[100005];
//LL drop[100005];
//
//// 快速幂求解算法 a^b mod n
//long long modExp(long long a, long long b, long long n) {
//    long long t, y;
//    t = 1;
//    y = a;
//    while (b) {
//        if (b % 2)
//            t = t * y % n;
//        y = y * y % n;
//        b >>= 1;
//    }
//    //    printf("%lld\n",t);
//    return t;
//}
//
//int main() {
//    //    modExp(2, 6, 63);
//    
//    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B "
//            "APAC Test 2017/B-small-practice.in",
//            "r", stdin);
//    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B "
//            "APAC Test 2017/B-pratice.out",
//            "w", stdout);
//    int T, t;
//    cin >> T;
//    t = 1;
//    LL N;
//    LL A, B, K;
//    LL ans;
//    //    cout<<mod<<endl;
//    while (T--) {
//        
//        cin >> A >> B >> N >> K;
//        ans = 0;
//        memset(acnt, 0, sizeof(acnt));
//        memset(bcnt, 0, sizeof(bcnt));
//        memset(drop, 0, sizeof(drop));
//        
//        // ((i+k)^A)%k==(i^A)%k
//        //        也就是说，k=100000的时候，i=1和i=100001的结果是一样的
//        //        或者说，我算出来i=1的结果，我就知道了1+k、1+2k、1+3k......的结果
//        //        所以，只需要考虑i=1到k的情况就行。
//        for (int i = 1; i <= min(N, K); i++) {
//            // count是指有N由多少个K组成，每一个K包含一个i。如果N小于K,则则count =1或0
//            LL count = (N / K + (N % K >= i ? 1 : 0)) % mod;
//            int ai = (int)modExp(i, A, K) % K;
//            int bi = (int)modExp(i, B, K) % K;
//            acnt[ai] += count;
//            bcnt[bi] += count;
//            if ((modExp(i, A, K) + modExp(i, B, K)) % K == 0) {
//                // 记录相同的i和j，以便后续减去相同的情况个数
//                drop[i % K] += count;
//            }
//        }
//        
//        for (int i = 0; i < K; i++) {
//            int other = (K - i) % K;
//            // ans 为acnt[i]*bcnt[other]的累加，因此可以对各自的acnt[i] 取模;
//            acnt[i] %= mod;
//            bcnt[other] %= mod;
//            ans += acnt[i] * bcnt[other] % mod;
//            // 减去相同的情况个数
//            ans -= drop[i];
//            ans %= mod;
//        }
//        
//        // 当ans-= drop[i]之后，可能为负数，需要加上一个mod
//        ans += mod;
//        ans %= mod;
//        
//        printf("Case #%d: %lld\n", t++, ans);
//    }
//    return 0;
//}
