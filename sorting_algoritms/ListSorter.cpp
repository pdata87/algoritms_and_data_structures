//
// Created by pdata on 12.05.17.
//

#include "ListSorter.h"

void ListSorter::sort(string algorithmType) {
    printList(this->unsortedList);
    this->sortingAlgorithm = algorithmType;
    if(sortVector()){
        printExecutionTime();
        printList(this->sortedList);
    }

}

bool ListSorter::sortVector() {

    if(this->sortingAlgorithm == "bubble"){
        // TODO : CODE REFACTOR -> too many duration measure functions
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        bubbleSort(unsortedList);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        this->algoritmExecutionTime = duration_cast<microseconds>( t2 - t1 ).count();
    }
    else if(this->sortingAlgorithm == "insert"){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        insertSort(this->unsortedList);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        this->algoritmExecutionTime = duration_cast<microseconds>( t2 - t1 ).count();
    }
    else if(this->sortingAlgorithm=="shell"){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        shellSort(this->unsortedList);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        this->algoritmExecutionTime = duration_cast<microseconds>( t2 - t1 ).count();
    }
    else {
        cout << "Undefined sorting algorithm" << endl;
        return false;
    }



    return  true;
}
void ListSorter::insertSort(vector<int> list) {
    // variable

    int i,j,tmp_value = 0;
    for(i = 1; i < list.size();i ++){                                           // iterate through list
        tmp_value = list[i];                                                //assign current element to temporary variable

        for(j = i-1; j>=0 && list[j]>tmp_value;j--){                            // socond loop iterates through array until current element is greater than temporary variable
            list[j+1] = list[j];                                                // replace values (next -> current)

        }
        list[j+1] = tmp_value;                                                  // replace values

    }

    this->sortedList = list;

}

void ListSorter::shellSort(vector<int> list) {

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

    this->sortedList = list;
}
void ListSorter::bubbleSort(vector<int> list) {


    for( int i = 0; i < list.size(); i++ )
    {

        for( int j = 0; j < list.size() - 1; j++ )
        {

            if( list[ j ] > list[ j + 1 ] )     // if current value is greater than next one ....
            {

                int temp = list[ j ];           // asign current value to temporary variable
                list[ j ] = list[ j + 1 ];      // replace values
                list[ j + 1 ] = temp;           // assign current value to te next element of list

            }
        }
    }

    this->sortedList = list;
}
void ListSorter::printExecutionTime() {
    cout << "Execution time of "<< this->sortingAlgorithm <<  " algorithm was "<< this->algoritmExecutionTime <<" microseconds." << endl;

}
void ListSorter::printList(vector<int> &list) {
    for(int i =0; i<list.size(); i++){
        cout << i << " " << list[i] << endl;
    }
}