```cpp
class Solution{
public:
    int maxPoints(vector<vector<int>>& points){
        int n = points.size();
        if(n == 0)  return 0;
        int result = 0;
        for(int i = 0; i < n; ++i){
            map<pair<int,int>, int>  cnt;    //unordered_map不能接收pair
            int overlap = 0;
            int localmax = 0;
            for(int j = i+1; j < n; ++j){
                if(points[i][0] == points[j][0]  && points[i][1] == points[j][1])
                    ++overlap;
                else{
                    int deltx = points[i][0] - points[j][0];
                    int delty = points[i][1] - points[j][1];
                    int g = gcb(abs(deltx),abs(delty));
                    ++cnt[make_pair(deltx/g,delty/g)];
                    ++cnt[make_pair(-deltx/g,-delty/g)];    //x,y可同时取反
                    if(cnt[make_pair(deltx/g,delty/g)] > localmax)  
                        localmax = cnt[make_pair(deltx/g,delty/g)];   //不可以直接与result作比较，每一条直线的overlap不一致
                }
                
            }
            localmax = localmax + overlap;
            result = max(result,localmax);
        }
        return result+1;
    
    }
    int gcb(int a,int b){
        while(b){
            a= a%b;
            swap(a,b);
        }
        return a;
    }
};
```
