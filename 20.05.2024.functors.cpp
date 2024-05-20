#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SimpleFunctor0 {
    std::string name_;
public:
    SimpleFunctor0(const char* name) : name_(name) {}
    void operator()() { std::cout << "Welcome, " << name_ << endl; }
};

class Duplicator {
    int number_;
public:
    Duplicator(int number) : number_(number) {}
    int operator()() { return number_ * 2; }
};

class EvenOddFunctor {
    int even_;
    int odd_;
public:
    EvenOddFunctor() : even_(0), odd_(0) {}
    void operator()(int x) {
        if (x % 2 == 0) even_ += x;
        else odd_ += x;
    }
    int even_sum() const { return even_; }
    int odd_sum() const { return odd_; }
};

struct MultiplyFunctor {
    int multiplier;

    MultiplyFunctor(int mult) : multiplier(mult) {}

    int operator()(int x) {
        return x * multiplier;
    }
};

struct EndedBy0 {
    int multiplier_;

    EndedBy0(int multiplier) : multiplier_(multiplier) {}

    bool operator()(int x) {
        if (x % 10 == 0) return 1;
        else return 0;
    }
};

struct MakingNextRow {
    string old_str_;

    MakingNextRow(string some_string) : old_str_(some_string) {}

    string operator()(string s) {
        int counter = 1;
        int j = 1;
        string new_str;
        for (int i = 0; i < size(s); ) {
            if (s[i] != s[i + j]) {
                new_str += std::to_string(counter);
                new_str += s[i];
                j = 1;
                i+=counter;
                counter = 1;
            }
            else {
                counter++;
                j++;
            }
        }
        return new_str;
    }
};

int main()
{
    setlocale(0, "ru");

    SimpleFunctor0 sf("some_name");
    sf();  // выводит "Welcome, some_name"

    Duplicator dp(33);
    cout << "Вот удвоеное число: " << dp() << endl;

    EvenOddFunctor evenodd;
    int my_list[] = { 12, 3, 5, 8, 17, 4, 19 };
    evenodd = std::for_each(my_list, my_list + sizeof(my_list) / sizeof(int), evenodd);
    std::cout << "Сумма чётных: " << evenodd.even_sum() << endl;
    std::cout << "Сумма нечётных: " << evenodd.odd_sum() << std::endl;

    MultiplyFunctor mult_functor(3);
    int result = mult_functor(7);  // Результат: 21
    std::cout << "Result: " << result << std::endl;

    int num = 189840;
    EndedBy0 eb(num);
    cout << "То, что число " << num << " заканчивается на 0, это "<< eb(num) << endl;




    std::vector<int> numbers = { 5, 2, 7, 1, 8 };
    std::sort(numbers.begin(), numbers.end());


    numbers = { 5, 2, 7, 1, 8 };
    auto it = std::find(numbers.begin(), numbers.end(), 7);
    if (it != numbers.end()) {
        std::cout << "Element found at position: " << std::distance(numbers.begin(), it) << std::endl;
    }


    std::for_each(numbers.begin(), numbers.end(), [](int& num) { 
        num *= 2; 
    });


    numbers = { 5, 2, 7, 1, 8 };
    std::vector<int> doubled_numbers;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(doubled_numbers), [](int num) { return num * 2; });


    numbers = { 5, 2, 7, 1, 8 };
    int count = std::count(numbers.begin(), numbers.end(), 7);
    std::cout << "Count: " << count << std::endl;


    string user_row = "111221";
    MakingNextRow mnr(user_row);
    cout << "Изначальная строка: " << user_row << "\tСтрока, которую выдал функтор, основываясь на предыдущей: " << mnr(user_row) << endl;


    return 0;
}
