//
// Created by Seyyidahmed on 4/14/18.
//

#include "LFSR.h"


static void DecodeByteIntoEightBools(char theByte, bool *eightBools)
{
    for (int i=0; i<8; i++) eightBools[i] = ((theByte & (1<<i)) != 0);
}

static unsigned char unpackBits(bool b[8]){
    unsigned char c = 0;
    for (int i=0; i <8; ++i)
        if (b[i])
            c |= 1 << 8-i-1;
    return c;
}

void LFSR::parseKey(std::string s){
    if(s.length() == SIZE/8){
        auto t = new bool[8];
        unsigned int i=0;
        unsigned int j=0;
        while (i !=SIZE*8){
            char tmp = s.c_str()[j++];
            DecodeByteIntoEightBools(tmp,t);
            std::cout<<*t;

            for (int k = 0; k <8 ; ++k){
                bool res = (tmp & (1<<k)) != 0;
                this->reg[i] =res;
                ++i;
            }


        }
    }
    else
        std::cout<<"Key Initializatin failed";
}

LFSR::LFSR(){
    for (int i = 0; i <SIZE ; ++i) {
        this->reg.push_back(i % 4 == 0 or i % 5 == 0);
    }
}

bool LFSR::generateNextBit(){
    bool tmp = this->reg.back();
    this->reg.pop_back();
    //Function in = last xor out
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
