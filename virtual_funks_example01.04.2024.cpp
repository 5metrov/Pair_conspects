#include <iostream>
using namespace std;

//работа на паре
class Weapon {
public:
    virtual void shoot() { //все потомки могут переопределять метод виртуал
        cout << "BANG!" << endl;
    }
};

class Bazooka : public Weapon {
public:
    void shoot() override { //override деает проверку на уровне кампилятора. некий дополнительный контроль. void shoot(int n) override - будет ошибкой ибо изначальная функция не принимает никаких знчений
        cout << "BADABUM!" << endl;
    }
};

class Muchinegun : public Weapon {
public:
    void shoot() {
        cout << "TATATA!" << endl;
    }
};

class Tank : public Weapon {
public:
    void shoot() override {
        cout << "BDISH" << endl;
    }
};

class Player {
public:
    void shoot(Weapon* weapon) {
        weapon->shoot();
    }
};

void osn0() {
    Weapon weapon;
    Bazooka baz;
    Muchinegun mg;
    Tank tank;

    Player player;
    player.shoot(&weapon);
    player.shoot(&baz);
    player.shoot(&mg);
    player.shoot(&tank);
    cout << endl;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
/*тз: создать классы: родительский для всех действий,отдельно для каждого действия, для человека
реализовать так, чтобы с помощью различных действий человек мог перемещаться по разному: 
плыть, летать, карабкаться, телепортироваться*/
class Action {
public:
    virtual void act() {
        cout << "Некое перемещение" << endl;
    }
};

class Swim : public Action{
public:
    void act() override {
        cout << "*Плывёт*" << endl;
    }
};

class Fly : public Action {
public:
    void act() override {
        cout << "*Летит*" << endl;
    }
};

class Climd: public Action {
public:
    void act() override {
        cout << "*Карабкается*" << endl;
    }
};

class Tp : public Action {
public:
    void act() override {
        cout << "*Телепортируется*" << endl;
    }
};

class Person {
public:
    void someaction(Action* action) {
        action->act();
    }
};

void osn1() {
    Action action;
    Swim swim;
    Fly fly;
    Climd climb;
    Tp tp;

    Person person;
    person.someaction(&swim);
    person.someaction(&fly);
    person.someaction(&climb);
    person.someaction(&tp);
}

int main(){
    setlocale(LC_ALL, "ru");
    osn0();
    osn1();
    return 0;
}
