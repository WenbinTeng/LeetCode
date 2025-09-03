#include <string>
#include <vector>

class BrowserHistory {
  public:
    BrowserHistory(std::string homepage) { history.push_back(homepage); }

    void visit(std::string url) {
        index++;
        size = index + 1;
        if (index == history.size())
            history.push_back(url);
        else
            history[index] = url;
    }

    std::string back(int steps) {
        index = std::max(0, index - steps);
        return history[index];
    }

    std::string forward(int steps) {
        index = std::min((int)size - 1, index + steps);
        return history[index];
    }

  private:
    int index = 0;
    size_t size = 1;
    std::vector<std::string> history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */