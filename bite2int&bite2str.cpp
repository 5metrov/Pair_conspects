#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <sstream>
#include <string>
#define PRINT(x) cout << x << endl;
using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::cin;

static class Ten2two {
public:
    static std::string ten2two(int ten) {
        std::ostringstream stream;
        stream << std::bitset<8>(ten);
        return stream.str();
    }
};

static class Two2ten {
public:
    static int two2ten(string two) {
        /*bool num_started = 0; //флажок для корректной работы цикла дальше
        string pre_itog; //будущее число без нулей в начале
        for (int i = 0; i < size(two); i++) { //этот цикл отбрасывает нули из начала числа
            if (!num_started) {
                if (two[i] == '0') {
                    continue;
                }
                else {
                    num_started = 1;
                    pre_itog += two[i];
                }
            }
            else {
                pre_itog += two[i];
            }
        }*/

        int itog = 0;
        int multiplier = 1;
        int vrem_num_holder = stoi(two); //перезпись со строки в инт для более дуобной работы с переменной
        for (int i = 0; i < size(two); i++) { //в данном цикле идёт перевод числа из двоичной системы в десятичную
            if (vrem_num_holder % 10 == 1) {
                itog += multiplier;
            }
            multiplier *= 2;
            vrem_num_holder /= 10;
        }
        return itog;
    }
};

void osn0() {
    PRINT(Ten2two::ten2two(70));
    PRINT(Two2ten::two2ten("1111"));
}

static class Word2two {
public:
    static string word2two(string word) {
        std::ostringstream stream;
        for (char letter : word) {
            stream << std::bitset<8>(letter);
        }
        return stream.str();
    }
};

static class Two2Word {
public:
    static string two2Word(string two) {
        string itog = "";
        int size_str = two.length();
        int dd = sizeof(4);
        int twoi = stoi(two);
        for (int i = 0; i < size_str / 8; i++) {
            int tmp_int = (twoi % 100000000);
            itog += Two2ten::two2ten(std::to_string(twoi));
            twoi / 100000000;
        }
        return itog;
    }
};

void osn1() {
    PRINT(Word2two::word2two("hello"));
    std::string str = Word2two::word2two("H");
    PRINT(Two2Word::two2Word(str));
}

int main(){
    setlocale(0, "ru");
    srand(time(NULL));
    osn1();
    return 0;
}

