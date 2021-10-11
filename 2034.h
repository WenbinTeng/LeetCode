#include <vector>
#include <queue>
#include <unordered_map>

class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        currTime = std::max(currTime, timestamp);
        timeline[timestamp] = price;
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
    }
    
    int current() {
        return timeline[currTime];
    }
    
    int maximum() {
        auto m = maxHeap.top();
        while (m.first != timeline[m.second])
        {
            maxHeap.pop();
            m = maxHeap.top();
        }
        return m.first;
    }
    
    int minimum() {
        auto m = minHeap.top();
        while (m.first != timeline[m.second])
        {
            minHeap.pop();
            m = minHeap.top();
        }
        return m.first;
    }

private:
    int currTime = 0;
    std::unordered_map<int, int> timeline;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::   less<std::pair<int, int>>> maxHeap;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */