#include <string>
#include <vector>

class Bitset {
  public:
    Bitset(int size) {
        this->size = size;
        this->ones = 0;

        if (size % 32 == 0) {
            bits = std::vector<int>(size / 32);
        } else {
            bits = std::vector<int>(size / 32 + 1);
        }
    }

    void fix(int idx) {
        int loc = idx / 32;
        int off = idx % 32;

        if (bits[loc] & (1 << off) ^ (1 << off)) {
            ++ones;
            bits[loc] |= (1 << off);
        }
    }

    void unfix(int idx) {
        int loc = idx / 32;
        int off = idx % 32;

        if (bits[loc] & (1 << off)) {
            --ones;
            bits[loc] ^= (1 << off);
        }
    }

    void flip() {
        ones = size - ones;

        for (auto &num : bits) {
            num = ~num;
        }
    }

    bool all() { return ones == size; }

    bool one() { return ones > 0; }

    int count() { return ones; }

    std::string toString() {
        std::string res;

        for (int i = 0; i < size; ++i) {
            int loc = i / 32;
            int off = i % 32;

            if (bits[loc] & (1 << off)) {
                res.push_back('1');
            } else {
                res.push_back('0');
            }
        }

        return res;
    }

  private:
    std::vector<int> bits;
    int size;
    int ones;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */