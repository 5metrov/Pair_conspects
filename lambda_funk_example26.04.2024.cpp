#include <iostream>
using namespace std;

void ss(string mes, int a, int b, int (*some_funk)(int, int)) {
    cout << mes << ' ' << some_funk(a, b) << endl;
}

int sww(int _a, int _b) {
    return 999;
}

int main(){
    int a = 9;
    int a = 12;

    auto func_0 = [](int _a, int _b) {
        return 9999;
    };

    auto func_1 = [](int _a, int _b) {
        return _a + _b;
    };

    auto func_2 = [](int _a, int _b) {
        if (_a > _b) {
            return _a + _b;
        }
    };

    auto func_3 = [](int _a, int _b) {
        if (_a >= _b) {
            return _a - _b;
        }
        if (_a < _b) {
            return _b - _a;
        }
    };

    ss("Hello", a, b, func_0);
    ss("Afternoon", a, b, func_1);
    ss("Evning", a, b, func_2);

    return 0;
}
