#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() {}
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    void get_cords() {
        cout << "\tx: " << x << " y: " << y << endl;
    }
    Point operator + (Point& _p) { //создаём перегрузки операторов
        int tmp_x = x + _p.get_x();
        int tmp_y = y + _p.get_y();
        Point point(tmp_x, tmp_y);
        return point;
    }
    bool operator == (Point& _p) {
        if ((this->x == _p.get_x()) && (this->y == _p.get_y())) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator != (Point& _p) {
        if ((this->x != _p.get_x()) || (this->y != _p.get_y())) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator >= (Point& _p) {
        if ((this->x >= _p.get_x()) && (this->y >= _p.get_y())) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator <= (Point& _p) {
        if ((this->x <= _p.get_x()) && (this->y <= _p.get_y())) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator > (Point& _p) {
        if ((this->x > _p.get_x()) && (this->y > _p.get_y())) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator < (Point& _p) {
        if ((this->x < _p.get_x()) && (this->y < _p.get_y())) {
            return true;
        }
        else {
            return false;
        }
    }
    int get_x() { //тупо геттер
        return x;
    }

    int get_y() {
        return y;
    }
};

void osn() { //дз в следующей функции, это конспект с урока
    vector<Point> square; //создание вектора класса Point
    regex xPatern("^[0-9]+"); //нахождение чисел в строке при помощи регулярок
    regex yPatern("[0-9]+$");
    string path = "./text.txt"; //объявление пути к фалу
    ifstream reader; // объявление ридера
    reader.open(path); //открытие файла
    int a = 1;
    int tmp_x, tmp_y = 0;
    while (!reader.eof()) {
        string tmp_string;
        getline(reader, tmp_string);
        smatch m, n;
        if (regex_search(tmp_string, m, xPatern)) {
            tmp_x = (stoi(m[0]));
        }
        if (regex_search(tmp_string, n, yPatern)) {
            tmp_y = (stoi(n[0]));
        }
        Point tmp_point(tmp_x, tmp_y);
        square.push_back(tmp_point);
        cout << "Координаты точки номер " << a << " - x: " << tmp_x << " y: " << tmp_y << endl;
        a++;
    }
    reader.close();//закрытие файла. важная штука
}

void osn1() {
    vector<Point> points; //создание вектора класса Point
    int tmp_x, tmp_y = 0;
    for (int i = 0; i < 10; i++) {
        tmp_x = rand() % 101;
        tmp_y = rand() % 101;
        Point tmp_point(tmp_x, tmp_y);
        points.push_back(tmp_point);
        cout << "Координаты точки номер " << i + 1;
        tmp_point.get_cords();
    }

    Point max(-1, -1);
    Point min(101, 101);

    for (int i = 0; i < points.size(); i++) { //нахождение точки с максимальными координатами
        if (max < points[i]) {
            max = points[i];
        }
        else {
            continue;
        }
    }
    cout << endl << "Точка с максимальными кординатами: ";
    max.get_cords();

    for (int i = 0; i < points.size(); i++) { //нахождение точки с минимальными координатами
        if (min > points[i]) {
            min = points[i];
        }
        else {
            continue;
        }
    }
    cout << "Точка с минимальными кординатами: ";
    min.get_cords();
    cout << endl;
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
class Letter {
private:
    int adress;
    string senderFIO;
    string geterFIO;
public:
    int get_adress(){
        return adress;
    }
    string get_senderFIO() {
        return senderFIO;
    }
    string get_geterFIO() {
        return geterFIO;
    }
    void get_all() {
        cout << adress << ' ' << senderFIO << ' ' << geterFIO << endl;
    }
    Letter(string _senderFIO, string _geterFIO) {
        adress = rand() % 200;
        senderFIO = _senderFIO;
        geterFIO = _geterFIO;
    }

    bool operator == (Letter& _l) {
        if (this->adress == _l.get_adress()){
            return true;
        }
        else {
            return false;
        }
    }
    void operator != (Letter& _l) { //ужас
        _l.adress = 0;
    }
    bool operator > (Letter& _l) { //две криворабочuu перегрузки
        if (this->adress > _l.get_adress()) {
            return false;
        }
        else {
            return true;
        }
    }
    bool operator < (Letter& _l) {
        if (this-> adress < _l.get_adress()) {
            return false;
        }
        else {
            return true;
        }
    }
};

ostream& operator << (ostream& stream, Letter& _letter)
{
    stream << "Адрес: ";
    stream << _letter.get_adress() << " от кого: " << _letter.get_senderFIO() << " для кого: " << _letter.get_geterFIO() << endl;
    return stream;
}

void osn2() {
    vector <Letter> letters;
    for (int i = 0; i < 100; i++) {
        Letter tmp_letter("Barinov Viktor Petrovich", "Lavrov Oguzok Invalidovich");
        letters.push_back(tmp_letter);
    }

    bool flag = 0;
    int counter = 1;
    int MOREcounter = 0;
    for (int i = 0; i < 99 - MOREcounter; i++) {
        for (int j = i + 1; j < 100 - MOREcounter; j++) {
            if ((letters[i] == letters[j]) && (flag == 0)) {
                cout << "Совпадение адресов номер " << counter << endl; 
                cout << letters[i];
                flag = 1;
                counter++;
            } 
            if ((letters[i] == letters[j]) && (flag == 1)) {
                cout << letters[j];
                letters.erase(letters.begin() + j);
                MOREcounter++;
            }
        }
        flag = 0;
    }

    cout << endl; //игрульки с  ужасными перегрузками
    cout << letters[1];
    cout << letters[2];
    bool itog =  letters[1] < letters[2];
    cout << "Первое меньше второго? " << itog << endl;
    itog = letters[1] > letters[2];
    cout << "Первое больше второго? " << itog << endl << endl;

    letters[1] != letters[2];
    cout << letters[2];
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    osn2();
    return 0;
}
