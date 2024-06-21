
#include <string>
#include "Utilities.h"

using std::string;


string hash(int key, const string& value1, const string& value2) {
    static const int out_size = 20;
    char bytes[out_size + 1] = {0};
    for (int i = 0; i < out_size; i++) {
        bytes[i] = key ^ (out_size - i);
    }
    for (size_t i = 0; i < value1.size() * out_size ; i++) {
        bytes[i % (out_size/2)] ^= value1[i % value1.size()] ^ i;
    }
    for (size_t i = 0; i < value2.size() * out_size ; i++) {
        bytes[(out_size/2) + (i % out_size/2)] ^= value2[i % value2.size()] ^ i;
    }
    for (int i = 0; i < out_size; i++) {
        bytes[i] &= 0x0f;
        bytes[i] += (bytes[i] < 10) ? '0' : 'a' - 10;
    }
    return string(bytes);
}


string getErrorMessage() {
    return "Usage: ./mtm_blockchain <op> <source> <target> ";
}
