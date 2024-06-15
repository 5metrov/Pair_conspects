#include <iostream>
#include <thread>
#include <chrono>

void some_funk(int sec, std::string name) {
    for (int i = 0; i < 5; i++){
        std::cout << std::this_thread::get_id() << ' ' << "some_funk " << i << ' ' << name << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void osn0() {

    for (int i = 0; i < 5; i++) {
        std::cout << std::this_thread::get_id() << " osn0 " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::thread th_0(some_funk, 300, "th_0");//в скобках сначала название функции, а через запятую уже подаваемые в неё значения

    th_0.join();//дождаться выполнения потока th_0 перед тем как идти дальлше

    std::thread th_1(some_funk, 2000, "th_1");
    th_1.join();
}

int main(){
    osn0();
    return 0;
}

