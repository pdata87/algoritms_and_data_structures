//
// Created by pdata on 01.06.17.
//

#ifndef HUFFMAN_CODING_HUFFMANNODE_H
#define HUFFMAN_CODING_HUFFMANNODE_H


class HuffmanNode {


public:

    HuffmanNode(int freq, char value);
    HuffmanNode(HuffmanNode * left, HuffmanNode  * right);
    HuffmanNode();

    bool operator<(const HuffmanNode & other);

    bool IsRoot();
    bool IsLeaf();
    char GetValue();
    HuffmanNode * GetLeft();
    HuffmanNode * GetRight();
    HuffmanNode * GetParent();
    int Frequency;
    //TODO : move to private
    int bit;
private:

    bool Leaf;



    HuffmanNode * Left;
    HuffmanNode * Right;
    HuffmanNode * Parent;

    char Value;


};


#endif //HUFFMAN_CODING_HUFFMANNODE_H
