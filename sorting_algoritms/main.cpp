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
    int no_of_elements = 200;
    long sorting_time;
    fill_with_random_value(list_to_sort,no_of_elements);
    cout << "Before sorting" << endl;
    sorting_time = insert_sort(list_to_sort);
    cout << "Insert sort took :" << sorting_time <<endl;
    sorting_time = shell_sort(list_to_sort);

    cout << "Shell sort took :" << sorting_time <<endl;

    sorting_time = bubble_sort(list_to_sort);

    cout << "Bubble sort took :" << sorting_time <<endl;



    return 0;
}
void fill_with_random_value(vector < int > &vector_to_fill, int no_of_elements){
    srand(time(NULL));
    for(int i =0; i<no_of_elements; i++){
        // fill vector with random values;
        vector_to_fill[i] = rand() % 90;
    }

}
void display_array_values(vector < int > &vector_to_display){

    for(int i =0; i<vector_to_display.size(); i++){
        cout << i << ":" << vector_to_display[i]<<  endl;
    }

}

long insert_sort(vector <int> list){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int i,j,tmp_value = 0;
    for(i = 0; i < list.size();i ++){
            tmp_value = list[i];

        for(j = i-1; j>=0 && list[j]>tmp_value;j--){
            list[j+1] = list[j];

        }
        list[j+1] = tmp_value;

    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    long duration = duration_cast<microseconds>( t2 - t1 ).count();
    return duration;

}
long shell_sort (vector <int> list){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int gap,i;

    for(gap = list.size()/2; gap > 0; gap=gap/2){



        for (int i = gap; i < list.size(); i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = list[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && list[j - gap] > temp; j -= gap)
                list[j] = list[j - gap];

            //  put temp (the original a[i]) in its correct location
            list[j] = temp;
        }


    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    long duration = duration_cast<microseconds>( t2 - t1 ).count();
    return duration;
}
long bubble_sort(vector <int> list){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for( int i = 0; i < list.size(); i++ )
    {
        for( int j = 0; j < list.size() - 1; j++ )
        {
            if( list[ j ] > list[ j + 1 ] )
            {

                    int temp = list[ j ];
                    list[ j ] = list[ j + 1 ];
                    list[ j + 1 ] = temp;

            }
        }
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    long duration = duration_cast<microseconds>( t2 - t1 ).count();
    return duration;
}