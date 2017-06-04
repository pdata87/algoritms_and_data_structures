#include <iostream>
#include "Huffman.h"

int main() {


    const std::string stringToDecode = "sample string to encode";
    Huffman h(stringToDecode);
    std::vector<int> encoding;
    encoding = h.Encode(stringToDecode);
    std::vector<char> decoded =   h.Decode(encoding);

    return 0;
}