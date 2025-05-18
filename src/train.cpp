// Copyright 2021 NNTU-CS
#include "train.h"
#include <stdexcept>

Train::Train(): entry(nullptr), countOp(0) {}

Train::~Train() {
    if (!entry) return;
    // удалить все вагоны
    Car* cur = entry->next;
    while (cur != entry) {
        Car* next = cur->next;
        delete cur;
        cur = next;
    }
    delete entry;
}

void Train::addCar(bool light) {
    Car* car = new Car(light);
    if (!entry) {
        entry = car;
        entry->next = entry;
        entry->prev = entry;
    } else {
        Car* tail = entry->prev;
        tail->next = car;
        car->prev = tail;
        car->next = entry;
        entry->prev = car;
    }
}

int Train::getLength() {
    if (!entry) return 0;
    // простой алгоритм: идти по кругу до возвращения в entry, считая
    int n = 1;
    Car* cur = entry->next;
    // каждый переход ++countOp
    while (cur != entry) {
        countOp++;
        n++;
        cur = cur->next;
    }
    return n;
}

int Train::getOpCount() const {
    return countOp;
}
