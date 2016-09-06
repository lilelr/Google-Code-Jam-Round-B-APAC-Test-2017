#include <algorithm>
#include <ctype.h>
#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;

int T, Case = 1;

struct Point {
    int id;
    int idx;
    int type; // 0->delete,1->add
    Point() {}
    //    Point(int a, int b, int c) : id(a), idx(b), type(c) {}
    //    bool operator<(const Point &b) const {
    //        if (idx != b.idx)
    //            return idx < b.idx;
    //        return type > b.type;
    //    }
    Point(int a,int b,int c): id(a),idx(b),type(c){}
    //增序
    bool operator<(const Point &b) const{
        if (idx!=b.idx){
            return idx <b.idx;
        }
        return type > b.type;
    }
} p[1000005];

int singleLength[500005];

int main() {
    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B APAC Test 2017/C-small.in","r",stdin);
    freopen("/Users/yuxiao/XcodeProject/gcj Round B APAC Test 2017/gcj Round B APAC Test 2017/C-small.out","w",stdout);
    
    for (scanf("%d", &T); Case <= T; Case++) {
        int n, L1, R1, A, B, C1, C2, m;
        scanf("%d", &n);
        scanf("%d%d%d%d%d%d%d", &L1, &R1, &A, &B, &C1, &C2, &m);
        p[0] = Point(1, L1, 1);
        p[1] = Point(1, R1 + 1, 0);
        for (int i = 1; i < n; i++) {
            int xi, yi;
            xi = ((ll)A * L1 + (ll)B * R1 + C1) % m;
            yi = ((ll)A * R1 + (ll)B * L1 + C2) % m;
            p[2 * i] = Point(i + 1, min(xi, yi), 1);
            p[2 * i + 1] = Point(i + 1, max(xi, yi) + 1, 0);
            L1 = xi;
            R1 = yi;
        }
        sort(p, p + 2 * n);
        //        for (int i=1; i<=n; i++) {
        //            cout<<p[i].id<<" "<<p[i].idx<<" "<<p[i].type<<endl;
        //        }
        int totLength = 0;
        int lastStart = 0;
        int lastSingleStart = 0;
        int lastSingleId = 0;
        int maxSingle = 0;
        map<int,int> singles;
        set<int> hashCovered;
        for (int i=0; i<2*n; i++) {
            
            //            if(lastSingleStart!=0 && hashCovered.size()==1){
            //                singles[lastSingleId] = p[i].idx - lastSingleStart;
            //            }
            
            if (p[i].type == 1) {
                hashCovered.insert(p[i].id);
            }else{
                hashCovered.erase(p[i].id);
            }
            
            if (p[i].type == 1 && hashCovered.size() == 1) {
                lastStart = p[i].idx;
            }else if(p[i].type == 0 && hashCovered.size() == 0){
                totLength += (p[i].idx-lastStart);
            }
            // lastSinleId == 0 && hashCovered.size() >=1 则此时i遍历在重合线段的点上
            // 若lastSingleId == 0 && hashCovered.size() == 1 则为single 的起点，需要更新lastSingleStart和lastSingleId
            if (lastSingleId == 0 && hashCovered.size() == 1) {
                lastSingleStart = p[i].idx;
                lastSingleId = *(hashCovered.begin());
                //若lastSingleId != 0 && hashCovered.size()!=1 则为single 的终点
            } else if(lastSingleId != 0 && hashCovered.size()!=1 ){
                singles[lastSingleId]+=p[i].idx-lastSingleStart;
                lastSingleId = 0;
            }
        }
        
        for (auto it=singles.begin(); it!=singles.end(); it++) {
            maxSingle = max(maxSingle,it->second);
        }
        printf("Case #%d: %d\n", Case, totLength - maxSingle);
    }
    return 0;
}
