#include <vector>
#include <unordered_map>
#include <algorithm>

class RangeFreqQuery {
public:
    RangeFreqQuery(std::vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
        {
            um[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (um.find(value) == um.end()) return 0;
        
        auto& v = um[value];
        auto r = std::upper_bound(v.begin(), v.end(), right);
        auto l = std::upper_bound(v.begin(), v.end(), left - 1);
        return r - l;
    }

private:
    std::unordered_map<int, std::vector<int>> um;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */