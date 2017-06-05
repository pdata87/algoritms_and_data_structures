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

    long algoritmExecutionTime =0; // algorithm execution time to compare;
    string sortingAlgorithm;



    bool sortVector();
    void insertSort(vector <int> list);
    void shellSort (vector <int> list);
    void bubbleSort(vector <int> list);

    void printExecutionTime();
    void printList(vector <int> &list);

public:
    ListSorter(vector <int> vectorToSort){
        this->unsortedList = vectorToSort;
    }
    ListSorter(vector <int> vectorToSort, string sortingAlgorithm):unsortedList(vectorToSort),sortingAlgorithm(sortingAlgorithm){

        if(this->sortVector()){
            printExecutionTime();
            printList(this->sortedList);
        }
    }
    void sort(string algorithmType);


};

