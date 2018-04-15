#include "lfsr/LFSR.h"



int main() {
    LFSR a;

    a.parseKey("AAAAAAAAAAAAAAAA");
    std::string c = a.encrypt_decrypt("Test Sucess");

    std::cout<<c<<std::endl;
    LFSR b;
    b.parseKey("AAAAAAAAAAAAAAAA");
    std::cout<<b.encrypt_decrypt(c);


    return 0;
}