/*
simple example off testing funk:
int sum(int a, int b) {
    return a + b;
}
void sum_test(int a, int b, int itog) {
    cout << "Было введено: a = " << a << '\t' << "b = " << b << endl;
    cout << "Ожидаемый итог: " << itog << endl << "Фактический итог: " << a + b << endl;
    if ((a + b) == itog) {
        cout << "Сложение происходит корректно" << endl;
    }
    else { 
        cout << "Сложение происходит НЕ корректно" << endl;
    }
}
int main(){
    setlocale(LC_ALL, "ru");
    sum_test(7, 3, 10);
    sum_test(2, 6, 13);
    return 0;;
}
*/
#include <iostream>
#include <string>
using namespace std;
//a++ - постфиксный инкремент - сначала выполняется всё выражение, после постфиксный инкремент. ++a - префексный инкремент, сначала происходит инкремент, после выполняется всё выражение.
//тз - создать автотест для данной функции
string get_str(int num) {
    string str;
    for (int i = 0; i < num; i++) {
        str += to_string(i);

        if (i != (num - 1)) {
            str += ' ';
        }
    }

    return str;
}

bool get_str_TEST(int num) {
    int num_test = 5;
    string true_string = "0 1 2 3 4";
    string str = get_str(num_test);
    for (int i = 0; i < num_test * 2 - 1; i++) {
        if (sizeof(true_string) == sizeof(str)) {
            if (true_string[i] != str[i]) {
                cout << "Функция сработала не корректно" << endl;
                cout << "Ошибка происходит в элементе по индексу номер - " << i << endl;
                return false;
            }
            else {
                continue;
            }
        }
        else {
            cout << "Функция работает некорректно, в строках разне колличество символов!" << endl;
            return false;
        }
    }
    cout << "Функция сработала корректно, мои поздравления!" << endl;
    return true;
}

int main(){
    setlocale(LC_ALL, "ru");
    int num = 5;
    get_str_TEST(num);
    cout << endl;

    return 0;
}
