#include <iostream>
#include "Huffman.h"

int main() {


    const std::string stringToDecode = "this is an example for huffman encoding";
    Huffman h(stringToDecode);
    std::vector<int> encoding;
    encoding = h.Encode(stringToDecode);


    return 0;
}