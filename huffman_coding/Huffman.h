//
// Created by pdata on 01.06.17.
//

#ifndef HUFFMAN_CODING_HUFFMAN_H
#define HUFFMAN_CODING_HUFFMAN_H


#include <map>
#include <vector>
#include "HuffmanNode.h"

class Huffman {
    std::map< char,HuffmanNode*> Leafs;
    HuffmanNode * Root;

public:
    Huffman();
    Huffman( std::string  stringToDecode);
    std::vector<int>Encode(char value);
    void Encode(char value, std::vector<int> & list);
    std::vector<int> Encode(std::string values);
    char Decode(std::vector<int>, int & position);
    std::vector<char>Decode(std::vector<int> bits);

};


#endif //HUFFMAN_CODING_HUFFMAN_H
