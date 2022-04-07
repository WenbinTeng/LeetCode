#include <vector>
#include <string>
#include <unordered_map>

class Encrypter {
public:
    Encrypter(std::vector<char>& keys, std::vector<std::string>& values, std::vector<std::string>& dictionary) {
        this->keys = keys;
        this->values = values;
        this->dictionary = dictionary;

        for (int i = 0; i < keys.size(); ++i)
        {
            encodeTable[keys[i]] = values[i];
        }

        for (int i = 0; i < dictionary.size(); ++i)
        {
            ++decodeTable[encrypt(dictionary[i])];
        }
    }
    
    std::string encrypt(std::string word1) {
        std::string res;

        for (const auto c : word1)
        {
            res += encodeTable[c];
        }

        return res;
    }
    
    int decrypt(std::string word2) {
        return decodeTable[word2];
    }

private:
    std::vector<char> keys;
    std::vector<std::string> values;
    std::vector<std::string> dictionary;
    std::unordered_map<char, std::string> encodeTable;
    std::unordered_map<std::string, int> decodeTable;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */