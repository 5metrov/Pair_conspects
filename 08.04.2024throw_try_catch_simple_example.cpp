#include <iostream>
#include <cmath>
using namespace std;

double divide(int a, int b) {
    if (b) {
        double result = (double)a / b;
        return result;
    }
    throw "Либо вы ввели ноль вторым числом, либо ввели НЕ числа, попробуйте ещё раз\n";
    //throw string{ "Увы на нуль делить нельзя\n" }; так тоже можно, тогда в катче будет заместо конст чар* - стринг
}

int main(){
    setlocale(LC_ALL, "ru");
    int unum0;
    cout << "Введите делимое: " << endl;
    cin >> unum0;
    int unum1;
    cout << "Введите делелитель: " << endl;
    cin >> unum1;
    try {
        double result = divide(unum0, unum1);
        cout << result << endl;
    } catch (const char* error_messege){ //катч и три точки в круглых скобках значит - лови ЛЮБЫЕ trow
        cout << error_messege << endl;
    }
    cout << "the end" << endl; //програма доходит до конца, не обрывается
    return 0;
}
