#include <map>

class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int res = 0;
        int maxBook = 0;
        diff[startTime]++;
        diff[endTime]--;
        for (auto &[_, cnt] : diff) {
            maxBook += cnt;
            res = std::max(maxBook, res);
        }
        return res;
    }

private:
    std::map<int, int> diff;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */