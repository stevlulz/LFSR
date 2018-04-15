//
// Created by Seyyidahmed on 4/14/18.
//

#include "LFSR.h"

static void packToBits(unsigned char c, bool b[8])
{
    for (int i=0; i < 8; ++i){
        b[i] = (c & (1<<8-i-1)) != 0;

        std::cout<<b[i];
    }
}


static unsigned char unpackBits(bool b[8]){
    unsigned char c = 0;
    for (int i=0; i <8; ++i)
        if (b[i])
            c |= 1 << 8-i-1;
    return c;
}

//This method is used to change the initiale state with a user input
void LFSR::parseKey(std::string s){
    if(s.length() == SIZE/8){
        bool t[8];
        unsigned int i=0;
        unsigned int j=0;
        while (i !=SIZE*8){
            char tmp = s.c_str()[j++];
            packToBits(tmp,t);
            for (int k = 0; k <8 ; ++k){
                this->reg[i] =t[k];
                ++i;
            }


        }
    }
    else
        std::cout<<"Key Initializatin failed";
        std::cout<<"Key must be of length : "<<SIZE/8<<std::endl;
}

LFSR::LFSR(){
    for (int i = 0; i <SIZE ; ++i) {
        this->reg.push_back(i % 4 == 0 or i % 5 == 0);
    }
}

/**
 *
 * in  = Xor of all REGi  where  i < 20 or (i<10 && 3*i% 2 == 0 )
 *
 **/
bool LFSR::generateNextBit(){
    bool tmp = this->reg.back();
    this->reg.pop_back();
    bool in = reg[0]^tmp;
    reg.push_front(in);
    return in;
}

void LFSR::streamof(int i){
    while (i--){
        std::cout<<generateNextBit()<<std::endl;
        displayReg();

    }

}

void LFSR::displayReg(){
    for (int i = 0; i <reg.size() ; ++i) {
        std::cout<<reg[i];
    }
    std::cout<<std::endl;
}

unsigned char LFSR::generateNextKeyByte() {
    unsigned char ret;
    bool t[8];
    for (bool &i : t)
        i = generateNextBit();
    return unpackBits(t);

}

unsigned char LFSR::xorByte(unsigned char a, unsigned char b) {
    return a^b;
}

std::string LFSR::encrypt_decrypt(std::string s){
    std::string ret = "";
    for (int i = 0; i <s.length() ; ++i){
        ret +=xorByte((unsigned char)s[i], generateNextKeyByte());

    }
    return ret;
}

unsigned char LFSR::encrypt_decrypt(unsigned char b) {
    return xorByte(b,generateNextKeyByte());
}
