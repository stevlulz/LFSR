#include "lfsr/LFSR.h"



int main() {
    LFSR a;

    a.parseKey("AAbAbAAA");
    std::string c = a.encrypt_decrypt("Test Sucess");

    std::cout<<c<<std::endl;
    LFSR b;
    b.parseKey("AAbAbAAA");
    std::cout<<b.encrypt_decrypt(c);


    return 0;
}