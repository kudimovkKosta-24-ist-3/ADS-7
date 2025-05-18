// Copyright 2022 NNTU-CS
#include <cstddef>
class Train {
 private:
  struct Car {
    bool light;
    Car* next;
    Car* prev;
    Car(bool state = false) : light(state), next(nullptr), prev(nullptr) {}
  };
  Car* start;
  size_t size;
  unsigned long long countOp;

 public:
  Train();
  ~Train();
  void addCar(bool light);
  size_t getLength();
  unsigned long long getOpCount() const;
  void clear();
};
