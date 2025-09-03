#include <string>
#include <unordered_map>
#include <vector>

class OrderedStream {
  public:
    OrderedStream(int n) { this->n = n; }

    std::vector<std::string> insert(int idKey, std::string value) {
        std::vector<std::string> res;

        um[idKey] = value;
        if (um.count(idKey)) {
            for (int i = ptr; i <= n; ++i) {
                if (um.count(i)) {
                    res.push_back(um[i]);
                } else {
                    ptr = i;
                    break;
                }
            }
        }

        return res;
    }

  private:
    int n;
    int ptr = 1;
    std::unordered_map<int, std::string> um;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */