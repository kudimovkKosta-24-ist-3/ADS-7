// Copyright 2022 NNTU-CS
##include "train.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

// Инициализация поезда длины n с тремя режимами
Train makeTrain(int n, int mode, mt19937& rng) {
    // mode: 0 = все off, 1 = все on, 2 = random
    Train tr;
    uniform_int_distribution<int> d(0,1);
    for (int i = 0; i < n; ++i) {
        bool state = (mode==0 ? false : (mode==1 ? true : d(rng)));
        tr.addCar(state);
    }
    return tr;
}

int main() {
    vector<int> sizes;
    for (int n = 10; n <= 1000; n += 10) sizes.push_back(n);

    mt19937 rng(123);
    ofstream ops_out("result/ops.csv");
    ofstream time_out("result/time.csv");
    ops_out << "n,off,on,rand\n";
    time_out << "n,off,on,rand\n";

    for (int n : sizes) {
        vector<long long> ops(3);
        vector<double> times(3);
        for (int mode = 0; mode < 3; ++mode) {
            Train tr = makeTrain(n, mode, rng);
            auto start = chrono::high_resolution_clock::now();
            tr.getLength();
            auto end = chrono::high_resolution_clock::now();
            ops[mode] = tr.getOpCount();
            times[mode] = chrono::duration<double>(end - start).count();
        }
        ops_out << n << "," << ops[0] << "," << ops[1] << "," << ops[2] << "\n";
        time_out << n << "," << times[0] << "," << times[1] << "," << times[2] << "\n";
        cout << "n="<<n<<" ops(off,on,rand)="<<ops[0]<<","<<ops[1]<<","<<ops[2]
             <<" time="<<times[0]<<","<<times[1]<<","<<times[2]<<"\n";
    }
    return 0;
}
