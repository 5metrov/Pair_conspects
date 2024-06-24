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

static class Num2bin {
public:
    static std::string ten2bin(int num) {
        std::ostringstream stream;
        stream << std::bitset<8>(num);
        return stream.str();
    }
};

static class Bin2num {
public:
    static int bin2ten(string two) {
        int itog = 0;
        int multiplier = 1;
        int vrem_num_holder = stoi(two); //перезпись со строки в инт для более удобной работы с переменной
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
    //here is some tests 
    PRINT(Num2bin::ten2bin(70));
    PRINT(Bin2num::bin2ten("1111"));
}

static class Word2bin {
public:
    static string word2bin(string word) {
        std::ostringstream stream;
        for (char letter : word) {
            stream << std::bitset<8>(letter);
        }
        return stream.str();
    }
};

static class Bin2Word {
public:
    static string bin2word(string two) {
        string itog = "";
        int size_str = two.length();

        for (int i = 0; i < size_str; i += 8) {
            string byte_str = two.substr(i, 8); // отсекаем сегмент из 8ми бит
            int char_code = Bin2num::bin2ten(byte_str); // конвертим в десятичный код аски
            itog += static_cast<char>(char_code); // добавляем в строку
        }
        return itog;
    }
};

void osn1() {
    //here is some tests
    PRINT(Word2bin::word2bin("hello"));
    cout << Word2bin::word2bin(Bin2Word::bin2word("0110100001100101011011000110110001101111")) << endl; //"hello" in binary
    PRINT(Bin2Word::bin2word(Word2bin::word2bin("Hello i am working")));
}

int main() {
    setlocale(0, "ru");
    srand(time(NULL));
    osn1();
    return 0;
}
