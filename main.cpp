#include "lfsr/LFSR.h"

int main() {
    LFSR a,b;
    std::string key = "ABCDEF";
    int i=10;
    std::string ci = a.encrypt_decrypt(key);
    std::cout<<ci<<std::endl;

    std::cout<<b.encrypt_decrypt(ci)<<std::endl;

    return 0;
}