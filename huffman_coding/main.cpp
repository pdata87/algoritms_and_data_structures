#include <iostream>
#include "Huffman.h"

int main() {


    const std::string stringToDecode = "sample string to encode";
    Huffman huffmanEncoder(stringToDecode);
    std::vector<int> encoding;
    encoding = huffmanEncoder.Encode(stringToDecode);
    std::vector<char> decoded =   huffmanEncoder.Decode(encoding);

    return 0;
}