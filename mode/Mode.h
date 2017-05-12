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
        vector<int> mode_values;
    public:
        void setCounter(int value){
            this->counter = value;
        }

        void printModeInfo(){
            cout << "Mode counter " << this->counter << " times " << endl;
            for(int i=0; i <mode_values.size();i++){
                cout << "Mode value :" << mode_values[i]<< endl;
            }

        }
        void addModeValue(int value){
            this->mode_values.push_back(value);
        }
        void resetModeValues(){
            this->mode_values.erase(this->mode_values.begin(),this->mode_values.end());
        }


};


#endif //MODE_MODE_H
