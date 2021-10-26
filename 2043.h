#include <vector>

class Bank {
public:
    Bank(std::vector<long long>& balance) {
        this->balance.insert(this->balance.end(), balance.begin(), balance.end());
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 0 || account1 >= balance.size()) return false;
        if (account2 < 0 || account2 >= balance.size()) return false;
        if (balance[account1] < money) return false;

        balance[account1] -= money;
        balance[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 0 || account >= balance.size()) return false;
        balance[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 0 || account >= balance.size()) return false;
        if (balance[account] < money) return false;
        balance[account] -= money;
        return true;
    }

private:
    std::vector<long long> balance = std::vector<long long>(1);
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */