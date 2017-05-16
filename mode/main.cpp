#include <iostream>
#include <vector>
#include "Mode.h"
using namespace std;

void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements);
void display_list_values(vector<int> &vector_to_display);



int main() {
    int no_of_elements = 200;

    //random vector implementation
    vector <int> list(no_of_elements) ;
    fill_with_random_value(list,no_of_elements);

    //static vector implementation
    //vector <int> list = {1,2,3,4,5,6,7,1};
    display_list_values(list);

    Mode modes (list);

        modes.find_modes();
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


