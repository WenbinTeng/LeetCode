#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int k = lists.size();
        ListNode* ph = new ListNode();
        ListNode* pn = ph;

        std::vector<ListNode*> iterVec;
        iterVec.resize(k);
        for (int i = 0; i < k; i++)
        {
            iterVec[i] = lists[i];
        }

        std::vector<int> treeVec;
        treeVec.resize(k);
        for (auto& iter : treeVec)
        {
            iter = k;
        }

        std::vector<int> dataVec;
        dataVec.resize(k);
        dataVec.push_back(this->MIN_VAL);
        for (int i = 0; i < k; i++)
        {
            dataVec[i] = iterVec[i] ? iterVec[i]->val : this->MAX_VAL;
        }

        createLoserTree(treeVec, dataVec, k);

        while (dataVec[treeVec[0]] != this->MAX_VAL)
        {
            int minIndex = treeVec[0];

            pn->next = new ListNode(dataVec[minIndex]);
            pn = pn->next;

            iterVec[minIndex] = iterVec[minIndex]->next;
            dataVec[minIndex] = iterVec[minIndex] ? iterVec[minIndex]->val : this->MAX_VAL;

            adjustLoserTree(treeVec, dataVec, minIndex, k);
        }

        pn = ph->next;
        delete ph;
        return pn;
    }

private:
    const int MAX_VAL = +1e+4;
    const int MIN_VAL = -1e+4;

    void createLoserTree(std::vector<int>& treeVec, std::vector<int>& dataVec, int k)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            adjustLoserTree(treeVec, dataVec, i, k);
        }
    }

    void adjustLoserTree(std::vector<int>& treeVec, std::vector<int>& dataVec, int nodeNum, int k)
    {
        for (int i = (nodeNum + k) / 2; i > 0; i /= 2)
        {
            if (dataVec[nodeNum] > dataVec[treeVec[i]])
            {
                std::swap(nodeNum, treeVec[i]);
            }
        }
        treeVec[0] = nodeNum;
    }

};