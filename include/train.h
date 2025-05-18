// Copyright 2022 NNTU-CS
#include <cstddef>
class Train {
private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
    };
    Car* first;      // точка входа в поезд
    int countOp;     // счетчик переходов
public:
    Train();
    ~Train();
    void addCar(bool light);
    int getLength();    // вычислить длину поезда
    int getOpCount();   // вернуть число переходов
};

