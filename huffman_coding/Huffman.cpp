//
// Created by pdata on 01.06.17.
//

#include <iostream>
#include <queue>
#include <map>
#include <climits> // for CHAR_BIT
#include <iterator>
#include <algorithm>

#include "Huffman.h"
using namespace std;

struct HuffmanNodeComparer
{
    bool operator()(const HuffmanNode* left, const HuffmanNode* right) const { return left->Frequency > right->Frequency; }
};

std::vector<int> Huffman::Encode(std::string values) {

    std::vector<int> bits;

    for(auto character : values){
        Encode(character,bits);
    }

    return bits;
}


Huffman::Huffman(std::string stringToDecode) {
    map<char,int> characterCounter;
    priority_queue< HuffmanNode *, vector<HuffmanNode*>, HuffmanNodeComparer> queue;

    int overallCharactersCounter = 0;
    for(auto character : stringToDecode){
        //find character in temporary dictionary
        if(characterCounter.find(character) == characterCounter.end() ){
            // first occurence

            characterCounter.insert(pair<const char,int>(character,0));
        }
        characterCounter[character]++;
        overallCharactersCounter++;
    }
    // Creating node for each unique character in leafs maps
    for(pair<const char,int> character : characterCounter){

        //Create Huffman Nodes

        HuffmanNode * node  = new HuffmanNode(character.second,character.first);
        queue.push(node);

        Leafs[character.first] =  node;

    }

    while(queue.size()>1){

        HuffmanNode * left = queue.top();
        queue.pop();
        HuffmanNode * right = queue.top();
        queue.pop();
        HuffmanNode * parent = new HuffmanNode(left,right);
        queue.push(parent);

    }
    Root = queue.top();
    Root->bit=1;

}

std::vector<int> Huffman::Encode(char value) {

    return vector<int>();
}

void Huffman::Encode(char value, std::vector<int> &list) {

    HuffmanNode * node = Leafs[value];
    vector <int> encoding;
    while(!node->IsRoot()){
        cout << node->bit << endl;
        encoding.push_back(node->bit);
        node = node->GetParent();
    }
   reverse(encoding.begin(),encoding.end());
   list.insert(list.end(),encoding.begin(),encoding.end());

}
