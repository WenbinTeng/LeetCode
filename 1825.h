#include <queue>
#include <set>

class MKAverage {
public:
    MKAverage(int m, int k) : m(m), k(k), cnt(m - k * 2) {

    }
    
    void addElement(int num) {
        q.push(num);

        if      (ss.empty() || num <= *ss.rbegin())  ss.insert(num);
        else if (ms.empty() || num <= *ms.rbegin()) {ms.insert(num); sum += num;}
        else                                         ls.insert(num);

        if (q.size() > m)
        {
            if      (ss.find(q.front()) != ss.end())  ss.erase(ss.find(q.front()));
            else if (ms.find(q.front()) != ms.end()) {ms.erase(ms.find(q.front())); sum -= q.front();}
            else                                      ls.erase(ls.find(q.front()));

            q.pop();
        }

        while (ss.size() > k)
        {
            sum += *ss.rbegin();
            ms.insert(*ss.rbegin());
            ss.erase(std::prev(ss.end()));
        }
        while (ls.size() > k)
        {
            sum += *ls.begin();
            ms.insert(*ls.begin());
            ls.erase(ls.begin());
        }
        while (ms.size() > cnt)
        {
            if (ss.size() < k)
            {
                sum -= *ms.begin();
                ss.insert(*ms.begin());
                ms.erase(ms.begin());
                continue;
            }
            if (ls.size() < k)
            {
                sum -= *ms.rbegin();
                ls.insert(*ms.rbegin());
                ms.erase(std::prev(ms.end()));
                continue;
            }
        }
    }
    
    int calculateMKAverage() {
        return q.size() < m ? -1 : ((long long)sum / (long long)cnt);
    }

private:
    std::queue<int> q;
    std::multiset<int> ss;
    std::multiset<int> ms;
    std::multiset<int> ls;
    int m;
    int k;
    int cnt;
    long long sum = 0;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */