//
// Created by pdata on 12.05.17.
//
#include <iostream>
#include <vector>
using namespace std;
#ifndef MODE_MODE_H
#define MODE_MODE_H


class Mode {

        int counter = 0;
        vector<int> list;
        vector<int> mode_values;
    public:
        Mode(vector<int> &list);
        void setCounter(int value);
        void printModeInfo();
        void addModeValue(int value);
        void resetModeValues();
        void find_modes();


};


#endif //MODE_MODE_H
