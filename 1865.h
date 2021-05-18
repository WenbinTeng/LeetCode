#include <vector>
#include <unordered_map>

class FindSumPairs {
public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int i = 0; i < nums2.size(); ++i)
        {
            ++um[nums2[i]];
        }
    }
    
    void add(int index, int val) {
        int prev = nums2[index];
        int curr = nums2[index] + val;

        nums2[index] = curr;

        --um[prev];
        ++um[curr];
    }
    
    int count(int tot) {
        int cnt = 0;

        for (const auto& num : nums1)
        {
            cnt += um[tot - num];
        }

        return cnt;
    }

private:
    std::vector<int>& nums1;
    std::vector<int>& nums2;
    std::unordered_map<int, int> um;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */