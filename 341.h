#include <vector>
#include <stack>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    NestedIterator(std::vector<NestedInteger> &nestedList)
    {
        s.push({nestedList.begin(), nestedList.end()});
    }

    int next()
    {
        return (s.top().first++)->getInteger();
    }

    bool hasNext()
    {
        while (!s.empty())
        {
            if (s.top().first == s.top().second)
            {
                s.pop();
                continue;
            }
            if (s.top().first->isInteger())
                return true;

            auto &nextList = (s.top().first++)->getList();
            s.emplace(nextList.begin(), nextList.end());
        }

        return false;
    }

private:
    std::stack<std::pair<std::vector<NestedInteger>::iterator, std::vector<NestedInteger>::iterator>> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */