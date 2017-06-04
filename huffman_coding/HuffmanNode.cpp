//
// Created by pdata on 01.06.17.
//
#include <iostream>
#include <cmath>
#include <limits>
#include "HuffmanNode.h"

bool HuffmanNode::operator<(const HuffmanNode & other)   {


    bool greater =  this->Frequency < other.Frequency;
    return greater;

}

HuffmanNode::HuffmanNode(HuffmanNode * left, HuffmanNode * right):Left(left),Right(right)  {

    this->Frequency = left->Frequency + right->Frequency;
    Left->Parent = Right->Parent = this;
    Left->bit = 0;
    Right->bit= 1;
    this->Leaf = false;

}

HuffmanNode::HuffmanNode(int propability, char value){

    this->Leaf = true;
    this->Frequency = propability;
    this->Parent = NULL;
    this->Value = value;

}



HuffmanNode::HuffmanNode() {

}

bool HuffmanNode::IsRoot() {
    if(this->Parent==NULL)
        return  true;
    else{
        return false;
    }
}

HuffmanNode *HuffmanNode::GetParent() {
    return this->Parent;
}

bool HuffmanNode::IsLeaf() {
    return this->Leaf;
}

char HuffmanNode::GetValue() {
    return this->Value;
}

HuffmanNode *HuffmanNode::GetRight() {
    return this->Right;
}

HuffmanNode *HuffmanNode::GetLeft() {
    return this->Left;
}
