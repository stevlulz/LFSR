//
// Created by Seyyidahmed on 4/14/18.
//

#ifndef LINEARFEEDBACKSHIFTREGISTER_LFSR_H
#define LINEARFEEDBACKSHIFTREGISTER_LFSR_H
#define SIZE 64
#include <iostream>
#include <deque>

class LFSR {
    private:
        bool generateNextBit();
        void displayReg();
        unsigned char xorByte(unsigned char, unsigned char);
        unsigned char generateNextKeyByte();
        std::deque<bool> reg;

    public:
        LFSR();
        void parseKey(std::string);
        void streamof(int i);
        std::string encrypt_decrypt(std::string);
        unsigned char encrypt_decrypt(unsigned char);
};

#endif //LINEARFEEDBACKSHIFTREGISTER_LFSR_H
