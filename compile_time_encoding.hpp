// compile_time_encoding.hpp

#ifndef COMPILE_TIME_ENCODING_HPP
#define COMPILE_TIME_ENCODING_HPP

#include <cstddef>

template<char Key>
constexpr char xorEncrypt(char character) {
    return character ^ Key;
}

template<char Key, std::size_t N>
constexpr void encodeString(const char(&input)[N], char(&output)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        output[i] = xorEncrypt<Key>(input[i]);
    }
}

template<char Key, std::size_t N>
constexpr void decodeString(const char(&input)[N], char(&output)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        output[i] = xorEncrypt<Key>(input[i]);
    }
}

#endif // COMPILE_TIME_ENCODING_HPP
