// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : start(nullptr), size(0), countOp(0) {}

Train::~Train() {
    clear();
}

void Train::clear() {
    if (!start) return;
    Car* cur = start;
    size_t n = size;
    while (n-- > 0) {
        Car* nextCar = cur->next;
        delete cur;
        cur = nextCar;
    }
    start = nullptr;
    size = 0;
}

void Train::addCar(bool light) {
    Car* car = new Car(light);
    if (!start) {
        start = car;
        car->next = car;
        car->prev = car;
        size = 1;
    } else {
        Car* last = start->prev;
        last->next = car;
        car->prev = last;
        car->next = start;
        start->prev = car;
        size++;
    }
}

size_t Train::getLength() {
    if (!start) return 0;
    countOp = 0;
    if (!start->light) {
        start->light = true;
    }
    while (true) {
        Car* current = start;
        size_t steps_forward = 0;
        do {
            current = current->next;
            countOp++;
            steps_forward++;
            if (current->light) {
                current->light = false;
                for (size_t i = 0; i < steps_forward; ++i) {
                    current = current->prev;
                    countOp++;
                }
                if (!current->light) {
                    return steps_forward;
                }
                break;
            }
        } while (current != start);
    }
}

unsigned long long Train::getOpCount() const {
    return countOp;
}
