/*
task was:
-0) создать список на 100 элементов со случайными значениями не более 200
-1) вывести в консоль
-2) указать значение для первого элемента 201
-3) указать значение для второго элемента 202
-4) указать значение для крайнего элемента 203

-5) вывести в консоль значение 4 элемента
-6) вывести в консоль значение предпоследнего элемента 

-7) поменять местами значения первого и предпоследнего элем
*/
#include <iostream>
#include <vector>
#include <list>
#define elif else if
using::std::cout;
using::std::cin;
using::std::endl;
using::std::string;
using::std::vector;
using::std::list;

void osn0() {
	list<int> arr;
	for (int i = 0; i < 100; i++) {
		arr.push_back(rand() % 200);
	}

	for (int a : arr) { //№1
		cout << a << ' ';
	}
	cout << endl;

	arr.pop_front();//№2, №3
	arr.pop_front();
	arr.push_front(202);
	arr.push_front(201);

	arr.back() = 203; //№4

	list<int> deleted_numbers; //именно лист, а не вектор, чтобы был доступ к push_front
	for (int i = 0; i < 7; i++) { // №5
		if (i < 3) {
			deleted_numbers.push_front(arr.front());
			arr.pop_front();
		} elif (i == 3) { //0, 1, 2, 3.     3 - четвёртый элемент
			cout << "Число в споске под индексом 4: " << arr.front() << endl;
		} else {
			arr.push_front(deleted_numbers.front());
			deleted_numbers.pop_front();
		}
	}

	deleted_numbers.clear(); // №6
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			deleted_numbers.push_back(arr.back());
			arr.pop_back();
		} elif (i == 1) {
			cout << "Предпоследнеее число в списке: " << arr.back() << endl;
		} else {
			arr.push_back(deleted_numbers.front());
		}
	}

	for (int a : arr) { 
		cout << a << ' ';
	}
	cout << endl << endl;

	deleted_numbers.clear(); // №7
	int tmp_int;
	deleted_numbers.push_back(arr.back()); //запись последнего элемента в "удалённые переменные"
	arr.pop_back(); // дематерилизация последнего элемента arr
	tmp_int = arr.back(); // запись текущего последнего элемента во временную переменную
	arr.back() = arr.front(); // запись в текущий последний элемент значение первого элемента arr
	arr.front() = tmp_int; // запись в первый элемент бывшего значения последнего(те switсh их местами)
	arr.push_back(deleted_numbers.front()); //возврат удалённого последнего элемента arr обратно

	for (int a : arr) {
		cout << a << ' ';
	}
	cout << endl << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	osn0();
	return 0;
}
