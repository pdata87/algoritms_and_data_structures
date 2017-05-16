#include <iostream>
#include <vector>
#include <chrono>
#include "ListSorter.h"

using namespace std;
using namespace std::chrono;
void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements);
void display_array_values(vector < int > &vector_to_display);
long insert_sort(vector <int> list);
long shell_sort (vector <int> list);
long bubble_sort(vector <int> list);

int main() {
    vector < int > list_to_sort(200) ;

    long sorting_time;
    fill_with_random_value(list_to_sort,list_to_sort.size());

    //calling constructor only with vector and execute each algorithm

//    ListSorter ls(list_to_sort);
//
//        ls.sort("bubble");
//        ls.sort("insert");
//        ls.sort("shell");

    // calling constructor and execute sorting algoritm
    ListSorter ls(list_to_sort,"insert");


    return 0;
}
void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements){
    // fill vector with random integer values;
    srand(time(NULL));
    for(int i =0; i<no_of_elements; i++){
        // fill vector with random values;
        vector_to_fill[i] = rand() % 90;
    }

}

