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
        for(i = 0; i < list.size();i ++){
            tmp_value = list[i];

            for(j = i-1; j>=0 && list[j]>tmp_value;j--){
                list[j+1] = list[j];

            }
            list[j+1] = tmp_value;

        }
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        long duration = duration_cast<microseconds>( t2 - t1 ).count();
        this->algoritmExecutionTime=duration;
        this->sortedList = list;

    }
    void shellSort (vector <int> list){
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
        this->algoritmExecutionTime=duration;
        this->sortedList = list;
    }
    void bubbleSort(vector <int> list){
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

