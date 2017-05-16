#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;
void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements);
void display_array_values(vector < int > &vector_to_display);
long insert_sort(vector <int> list);
long shell_sort (vector <int> list);
long bubble_sort(vector <int> list);

int main() {
    vector < int > list_to_sort(5500) ;

    long sorting_time;


    fill_with_random_value(list_to_sort,list_to_sort.size());

    cout << "Before sorting" << endl;
    display_array_values(list_to_sort);



    cout << "--------------- SORTING -----------------------" << endl;

    sorting_time = insert_sort(list_to_sort);
    cout << "--------------- Insert sort took :" << sorting_time <<endl;
    sorting_time = shell_sort(list_to_sort);

    cout << "--------------- Shell sort took :" << sorting_time <<endl;

    sorting_time = bubble_sort(list_to_sort);

    cout << "--------------- Bubble sort took :" << sorting_time <<endl;



    return 0;
}
void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements){
    // fill vector passed by ref with with random values
    srand(time(NULL));
    for(int i =0; i<no_of_elements; i++){

        vector_to_fill[i] = rand() % 90;
    }

}
void display_array_values(vector < int > &vector_to_display){
    // Simple vector print
    for(int i =0; i<vector_to_display.size(); i++){
        cout << i << ":" << vector_to_display[i]<<  endl;
    }

}
// vector not send to list by ref because i'll use unsorted vector in next sorting algoritms
long insert_sort(vector <int> list){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int i,j,tmp_value = 0;
    for(i = 1; i < list.size();i ++){                                           // iterate through list
        tmp_value = list[i];                                                //assign current element to temporary variable

        for(j = i-1; j>=0 && list[j]>tmp_value;j--){                            // socond loop iterates through array until current element is greater than temporary variable
            list[j+1] = list[j];                                                // replace values (next -> current)

        }
        list[j+1] = tmp_value;                                                  // replace values

    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    long duration = duration_cast<microseconds>( t2 - t1 ).count();
    //return algorithm execution time
    display_array_values(list);
    return duration;

}
// vector not send to list by ref because i'll use unsorted vector in next sorting algoritms
long shell_sort (vector <int> list){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int gap,i;
    // split list until
    // initial : split list / 2
    //every iteration split gap  / 2 till result of division equals to 0
    for(gap = list.size()/2; gap > 0; gap=gap/2){


        // set i counter to curent gap index and iterate through this partitioned list
        for (int i = gap; i < list.size(); i += 1)
        {
            //store current element in temporary variable
            int temp = list[i];


            int j;
            // this loop iterates checks second part of partitioned list
            for (j = i; j >= gap && list[j - gap] > temp; j -= gap){
                // if value is greater than value on second partition, replace values
                list[j] = list[j - gap];
            }



            list[j] = temp;                                                     //asign temporeary value to current element
        }


    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    long duration = duration_cast<microseconds>( t2 - t1 ).count();
    display_array_values(list);
    return duration;
}
// vector not send to list by ref because i'll use unsorted vector in next sorting algoritms
long bubble_sort(vector <int> list){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    //iterate through list
    for( int i = 0; i < list.size(); i++ )
    {

        for( int j = 0; j < list.size() - 1; j++ )
        {

            if( list[ j ] > list[ j + 1 ] )         // if current value is greater than next one ....
            {

                int temp = list[ j ];           // asign current value to temporary variable
                list[ j ] = list[ j + 1 ];      // replace values
                list[ j + 1 ] = temp;           // assign current value to te next element of list

            }
        }
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    long duration = duration_cast<microseconds>( t2 - t1 ).count();
    display_array_values(list);
    return duration;
}