#include <string>

class Solution {
  public:
    bool isNumber(std::string s) {
        enum class State {
            INIT,
            SIGN,
            INTEGER,
            DOT_WITH_PREV_NUM,
            DOT_WITH_NONE_NUM,
            DOT,
            E_SYMB,
            E_SIGN,
            E
        };

        State state = State::INIT;

        for (const auto &iter : s) {
            switch (state) {
            case State::INIT:
                if (iter == '+' || iter == '-')
                    state = State::SIGN;
                else if (iter >= '0' && iter <= '9')
                    state = State::INTEGER;
                else if (iter == '.')
                    state = State::DOT_WITH_NONE_NUM;
                else
                    return false;
                break;

            case State::SIGN:
                if (iter >= '0' && iter <= '9')
                    state = State::INTEGER;
                else if (iter == '.')
                    state = State::DOT_WITH_NONE_NUM;
                else
                    return false;
                break;

            case State::INTEGER:
                if (iter >= '0' && iter <= '9')
                    state = State::INTEGER;
                else if (iter == '.')
                    state = State::DOT_WITH_PREV_NUM;
                else if (iter == 'e' || iter == 'E')
                    state = State::E_SYMB;
                else
                    return false;
                break;

            case State::DOT_WITH_PREV_NUM:
                if (iter >= '0' && iter <= '9')
                    state = State::DOT;
                else if (iter == 'e' || iter == 'E')
                    state = State::E_SYMB;
                else
                    return false;
                break;

            case State::DOT_WITH_NONE_NUM:
                if (iter >= '0' && iter <= '9')
                    state = State::DOT;
                else
                    return false;
                break;

            case State::DOT:
                if (iter >= '0' && iter <= '9')
                    state = State::DOT;
                else if (iter == 'e' || iter == 'E')
                    state = State::E_SYMB;
                else
                    return false;
                break;

            case State::E_SYMB:
                if (iter >= '0' && iter <= '9')
                    state = State::E;
                else if (iter == '+' || iter == '-')
                    state = State::E_SIGN;
                else
                    return false;
                break;

            case State::E_SIGN:
                if (iter >= '0' && iter <= '9')
                    state = State::E;
                else
                    return false;
                break;

            case State::E:
                if (iter >= '0' && iter <= '9')
                    state = State::E;
                else
                    return false;
                break;

            default:;
            }
        }

        return state == State::INTEGER || state == State::DOT ||
               state == State::DOT_WITH_PREV_NUM || state == State::E;
    }
};