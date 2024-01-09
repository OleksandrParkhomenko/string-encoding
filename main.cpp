// main.cpp

#include <iostream>
#include "compile_time_encoding.hpp"

int main() {
    constexpr const char originalString[] = "Hello, Compile-Time Encoding!";
    char encodedString[sizeof(originalString)];
    char decodedString[sizeof(originalString)];

    constexpr char customKey = 'Y';
    encodeString<customKey>(originalString, encodedString);
    decodeString<customKey>(encodedString, decodedString);

    std::cout << "Original: " << originalString << std::endl;
    std::cout << "Encoded: " << encodedString << std::endl;
    std::cout << "Decoded: " << decodedString << std::endl;

    // Check if the decoded string matches the original
    if (std::string(originalString) == std::string(decodedString)) {
        std::cout << "Decoding successful!" << std::endl;
    } else {
        std::cout << "Decoding failed!" << std::endl;
    }

    return 0;
}
