#include <algorithm>
#include <list>
#include <string>

class TextEditor {
public:
    TextEditor() {
        iter = word.begin();
    }

    void addText(std::string text) {
        for (const auto c : text) {
            word.insert(iter, c);
        }
    }

    int deleteText(int k) {
        int res = 0;

        while (k > 0 && iter != word.begin()) {
            iter = std::prev(iter);
            iter = word.erase(iter);
            --k;
            ++res;
        }

        return res;
    }

    std::string cursorLeft(int k) {
        while (k > 0 && iter != word.begin()) {
            iter = std::prev(iter);
            --k;
        }
        return getLeftText();
    }

    std::string cursorRight(int k) {
        while (k > 0 && iter != word.end()) {
            iter = std::next(iter);
            --k;
        }
        return getLeftText();
    }

private:
    std::list<char> word;
    std::list<char>::iterator iter;

    std::string getLeftText() {
        std::string res;

        auto iter = this->iter;

        for (int i = 0; i < 10; ++i) {
            if (iter == word.begin())
                break;
            iter = std::prev(iter);
            res.push_back(*iter);
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */