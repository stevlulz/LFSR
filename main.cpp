#include "lfsr/LFSR.h"



int main() {
    LFSR a;

    std::string c = a.encrypt_decrypt("AAAA");
    std::cout<<c<<std::endl;
    LFSR b;
    std::cout<<b.encrypt_decrypt(c);


    return 0;
}