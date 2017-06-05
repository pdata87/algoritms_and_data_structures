//
// Created by pdata on 01.06.17.
//

#include <iostream>
#include <queue>
#include <map>
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
    // encode each character
    for(auto character : values){
        Encode(character,bits);
    }

    return bits;
}


Huffman::Huffman(std::string stringToDecode) {
    map<char,int> characterCounter;
    //create priority quee based on frequency comparer
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
        //get two most frequent elements from quee and create new node with Left / Right child.
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
    //reverse order of bytes
   reverse(encoding.begin(),encoding.end());
    // and put it to bits list
   list.insert(list.end(),encoding.begin(),encoding.end());

}

std::vector<char> Huffman::Decode(std::vector<int> bits) {
    //Reverse decode
    int position = 0;
    vector<char> outputVector;

    while (position != bits.size())
    {
       outputVector.push_back(Decode(bits, position));
    }
    return outputVector;

}

char Huffman::Decode(std::vector<int> bits, int &position) {

    HuffmanNode * nodeCur = this->Root;
    while (!nodeCur->IsLeaf())
    {
        if (position > bits.size())
        {
            throw("Invalid bitstring");
        }
        nodeCur = bits[position++] == 0 ? nodeCur->GetLeft() : nodeCur->GetRight();
    }
    return nodeCur->GetValue();
}
