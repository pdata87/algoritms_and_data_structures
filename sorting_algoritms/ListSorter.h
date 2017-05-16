//
// Created by pdata on 12.05.17.
//


#ifndef SORTING_ALGORITMS_LISTSORTER_H
#define SORTING_ALGORITMS_LISTSORTER_H

#endif //SORTING_ALGORITMS_LISTSORTER_H

#include <vector>
#include <chrono>
#include <string>
#include <map>
#include <iostream>

using namespace std;
using namespace std::chrono;

class time_point;

class ListSorter {

    vector<int> unsortedList;
    vector<int> sortedList;
    long algoritmExecutionTime; // algorithm execution time to compare;
    string sortingAlgorithm;



    void sortVector(){
        if(this->sortingAlgorithm == "bubble"){
            bubbleSort(unsortedList);
        }
        else if(this->sortingAlgorithm == "insert"){
            insertSort(this->unsortedList);
        }
        else if(this->sortingAlgorithm=="shell"){
            shellSort(this->unsortedList);
        }
        else {
            cout << "Undefined sortin algorithm" << endl;
        }
    }
    void insertSort(vector <int> list){
        // variable
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
        this->algoritmExecutionTime=duration;
        this->sortedList = list;

    }
    void shellSort (vector <int> list){
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
        this->algoritmExecutionTime=duration;
        this->sortedList = list;
    }
    void bubbleSort(vector <int> list){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

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
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        long duration = duration_cast<microseconds>( t2 - t1 ).count();
        this->algoritmExecutionTime=duration;
        this->sortedList = list;
    }

    void printExecutionTime(){
        cout << "Execution time of "<< this->sortingAlgorithm <<  " algorithm was "<< this->algoritmExecutionTime <<" microseconds." << endl;

    }
    void printList(vector <int> &list){
        for(int i =0; i<list.size(); i++){
            cout << i << " " << list[i] << endl;
        }
    }

public:
    ListSorter(vector <int> vectorToSort){
        this->unsortedList = vectorToSort;
    }
    void sort(string algorithmType){
        printList(this->unsortedList);
        this->sortingAlgorithm = algorithmType;
        sortVector();
        printExecutionTime();
        printList(this->sortedList);
    }


};

