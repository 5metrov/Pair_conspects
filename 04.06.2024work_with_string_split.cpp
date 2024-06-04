#include <iostream>
#include <memory>
#include <string>

void couting(int x) {
    std::cout << "Вывод любой желаемой информации" << std::endl; 
    std::cout << "Например сообщений как это" << std::endl; 
    std::cout << "Или же переменных, которые мы можем передать в эту функцию " << x << std::endl;
}

int duplicating(int x) {
    return x * 2;
}

struct Some_struct {
public:
    int x;

    bool operator == (const Some_struct &first) {
        if(this->x == first.x){
            return true;
        }
        else {
            return false;
        }
    }
};

class Person {
private:
    std::string name;
    std::string sname;
    std::string tname;
    int birthDay;
    std::string birthMonth;
    int birthYear;
    std::string klikuha;
public:
    Person() {};
    Person(std::string _name, std::string _sname, std::string _tname, int _birthDay, std::string _birthMonth, int _birthYear, std::string _klikuha) {
        if (((_birthDay > 0) && (_birthDay < 32)) && (_birthYear > 0)) {
            this->name = _name;
            this->sname = _sname;
            this->tname = _tname;
            this->birthDay = _birthDay;
            this->birthMonth = _birthMonth;
            this->birthYear = _birthYear;
            this->klikuha = _klikuha;
        }
        else {
            std::cout << "Дата рождения введена некорректно" << std::endl;
        }
    }
    void show_all_stats() {
        std::cout << "Фамилия: " << name << std::endl;
        std::cout << "Имя: " << sname << std::endl;
        std::cout << "Отчество: " << tname << std::endl;
        std::cout << "Дата рождения: " << birthDay << birthMonth << birthYear << " года" << std::endl;
        std::cout << "Звание: " <<  klikuha << std::endl;
    }
};

int main()
{
    setlocale(0, "ru");
    unsigned short num1 = 0b00010000;
    unsigned short num2 = 0b00000011;
    unsigned short num3 = 0b00110000;
    unsigned short itog1, itog2, itog3;
    itog1 = num1 << 1;
    itog2 = num2 | 12;
    itog3 = num3 & 0 | 4;
    std::cout << itog1 << ' ' << itog2 << ' ' << itog3 << std::endl;
    int number = 1234;

    const int rows = 3;
    const int cols = 4;

    // Создание уникального указателя на массив уникальных указателей
    std::unique_ptr<std::unique_ptr<int[]>[]> array(new std::unique_ptr<int[]>[rows]);

    // Выделение памяти для каждой строки массива
    for (int i = 0; i < rows; ++i) {
        array[i] = std::make_unique<int[]>(cols);
    }

    // Инициализация элементов массива
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = i * cols + j;
        }
    }
    std::string some_str = "Александр Невский Ярославович 30 Май 1240 Невский";
    std::string str_arr[7];

    boost::split(str_arr, )

    Person an("Александр", "Невский", "Ярославович", 30, "Май", 1240, "Невский");
    an.show_all_stats();
}

