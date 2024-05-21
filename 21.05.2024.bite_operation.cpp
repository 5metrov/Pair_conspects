#include <iostream>
#include <bitset>
#define PRINT(x) std::cout << x << std::endl;

//если видишь запись 0b перед числом - это бинарное число 

int main(){
    setlocale(0, "ru");
    unsigned a = 0b00000011;
    unsigned b = 0b00000010;
    unsigned d = 0b11111111'11111111'111111'11111100;

    /*
    a & d = 2;
    a | d = 3;
    a ^ b = 1; это исключающее или
    ~d = 3; это отрицание
    (a << 2) = 12 (1100) добавление 2х битов в конец
    (12 >> 2) недослушал    
    */

    unsigned short user_choise;
    unsigned home_state_shina = 0b00000000;
    do {
        PRINT("Выберите ситуацию/или что бы вы хотели сделать:")
            PRINT("0 - [ситуация]Включена сигнализация")
            PRINT("1 - [ситуация]Пришли жильцы")
            PRINT("2 - Включить отопление")
            PRINT("3 - Выключить отопление")
            PRINT("4 - Включить сигнализацию)")
            PRINT("5 - Выключить сигнализацию)")
            PRINT("6 - Выпустить собак")
            PRINT("7 - Загнать собак")
            PRINT("8 - Начать приготовление стейка")
            PRINT("9 - Выключить приготовление стейка")
            PRINT("10 - Включить полив")
            PRINT("11 - Выключить полив")
            PRINT("12 - Выход из прогаммы")
            std::cin >> user_choise;

        switch (user_choise){
        case 0: {
            home_state_shina &= 0b00000000; 
            home_state_shina |= 0b00000110; 
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
            break; 
        }
        case 1: {
            home_state_shina &= 0b00000000; 
            home_state_shina |= 0b00011001; 
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
            break; 
        }
        case 2: {
            home_state_shina |= 1; 
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina)) 
            break;
        }
        case 3: {
            home_state_shina |= 1;
            home_state_shina ^= 1;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
            break; 
        }
        case 4: {
            home_state_shina |= 2;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 5: {
            home_state_shina |= 2;
            home_state_shina ^= 2;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 6: {
            home_state_shina |= 4;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 7: {
            home_state_shina |= 4;
            home_state_shina ^= 4;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 8: {
            home_state_shina |= 8;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 9: {
            home_state_shina |= 8;
            home_state_shina ^= 8;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 10: {
            home_state_shina |= 16;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 11: {
            home_state_shina |= 16;
            home_state_shina ^= 16;
            PRINT("Текущее состояние дома - " << std::bitset<5>(home_state_shina))
                break;
        }
        case 12: break; break;
        default: user_choise = 12; break;
        }
    
    } while (user_choise != 12);
}
