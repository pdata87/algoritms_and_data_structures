//
// Created by pdata on 12.05.17.
//

#include "Mode.h"
Mode::Mode(vector<int> &list) : list(list) {

}

void Mode::setCounter(int value) {
    this->counter = value;
}

void Mode::printModeInfo() {
    cout << "Mode counter " << this->counter << " times " << endl;
    for(int i=0; i <mode_values.size();i++){
        cout << "Mode value :" << mode_values[i]<< endl;
    }
}

void Mode::addModeValue(int value) {
    this->mode_values.push_back(value);

}

void Mode::resetModeValues() {
    this->mode_values.erase(this->mode_values.begin(),this->mode_values.end());

}

void Mode::find_modes() {
    int actual_mode_counter =0;
    int actual_mode_value;

    // itercja do konca vectora
    for(int i=0;i<this->list.size();i++){
        int temporary_counter =0; // this counter holds information about number of repetitions of a list[i] value
        for(int k = i;k<this->list.size();k++){

            if(list[i] == list[k]){
                temporary_counter++; // found repetition, increase counter
            }


        }
        if(temporary_counter>actual_mode_counter) // check if temporary counter is grater than stored counter;
        {
            actual_mode_counter = temporary_counter;
            actual_mode_value = this->list[i];

            setCounter(temporary_counter);
            resetModeValues();
            addModeValue(list[i]);
            //cout << "Found new most repetitive value " << list[i] << " exist in list " << temporary_counter <<" times" <<endl;
        }
        if(temporary_counter==actual_mode_counter && list[i] != actual_mode_value) // found new
        {
            actual_mode_counter = temporary_counter;
            addModeValue(this->list[i]);
            //cout << "Found new value "<< list[i]  << "which repreats "  << temporary_counter << " times in list "  <<endl;
        }
        //cout << list[i] << " found in list : " << temporary_counter <<" times " << endl;
    }

}
