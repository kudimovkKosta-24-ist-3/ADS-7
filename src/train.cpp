// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(): first(nullptr), countOp(0) {}

Train::~Train() {
    if (!first) return;
    // удаляем все вагоны
    Car* cur = first->next;
    while (cur != first) {
        Car* next = cur->next;
        delete cur;
        cur = next;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* car = new Car();
    car->light = light;
    if (!first) {
        first = car;
        first->next = first;
        first->prev = first;
    } else {
        Car* tail = first->prev;
        tail->next = car;
        car->prev = tail;
        car->next = first;
        first->prev = car;
    }
}

int Train::getLength() {
    if (!first) return 0;
    int n = 1;
    Car* cur = first->next;
    while (cur != first) {
        countOp++;
        n++;
        cur = cur->next;
    }
    return n;
}

int Train::getOpCount() {
    return countOp;
}
