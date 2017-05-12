#include <iostream>
#include <vector>
#include "Mode.h"
using namespace std;

void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements);
void display_list_values(vector<int> &vector_to_display);

Mode find_modes(vector<int> &list);

int main() {
    int no_of_elements = 200;
    //vector <int> list(no_of_elements) ;
    //fill_with_random_value(list,no_of_elements);
    vector <int> list = {1,2,3,1,1,1,1,1,1,1,1};

    display_list_values(list);

    Mode modes=    find_modes(list);
    modes.printModeInfo();
    return 0;
}
void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements){
    srand(time(NULL));
    for(int i =0; i<no_of_elements; i++){
        // fill vector with random values;
        vector_to_fill[i] = rand() % 45;
    }

}
void display_list_values(vector<int> &vector_to_display){

    for(int i =0; i<vector_to_display.size(); i++){
        cout << i << ":" << vector_to_display[i] <<  endl;
    }

}
Mode find_modes(vector<int> &list){

    int actual_mode_counter =0;
    int actual_mode_value;
    Mode modeValues;
    // itercja do konca vectora
    for(int i=0;i<list.size();i++){
        int temporary_counter =0; // this counter holds information about number of repetitions of a list[i] value
        for(int k = i;k<list.size();k++){

            if(list[i] == list[k]){
                temporary_counter++; // found repetition, increase counter
            }


        }
        if(temporary_counter>actual_mode_counter) // check if temporary counter is grater than stored counter;
        {
            actual_mode_counter = temporary_counter;
            actual_mode_value = list[i];

            modeValues.setCounter(temporary_counter);
            modeValues.resetModeValues();
            modeValues.addModeValue(list[i]);
            //cout << "Found new most repetitive value " << list[i] << " exist in list " << temporary_counter <<" times" <<endl;
        }
        if(temporary_counter==actual_mode_counter && list[i] != actual_mode_value) // found new
        {
            actual_mode_counter = temporary_counter;
            modeValues.addModeValue(list[i]);
            //cout << "Found new value "<< list[i]  << "which repreats "  << temporary_counter << " times in list "  <<endl;
        }
        //cout << list[i] << " found in list : " << temporary_counter <<" times " << endl;
    }

    return modeValues;

}

