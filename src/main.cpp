#include <stdio.h>
#include <math.h>
#include "wav_generator.h"

int gen_sin()
{
    wav_generator *gen = new wav_generator;
    int size = 20;
    int len = 44100 * size;
    for (int i = 0; i < len; ++ i) {
        double index = 1. * i / len * 3.14;
        char ch = (char)(sin(index) * 0xff);
        printf("%x ", ch);
        gen->append(&ch, 1);
    }
    gen->generate("sin.wav");
    return 0;
}

int gen_test()
{
    wav_generator *gen = new wav_generator;
    char ch = 0xa0;
    char ch1 = 0xaa;
    char ch2 = 0xff;
    for (int i = 0; i < 44100 * 5; ++ i) {
        gen->append(&ch, 1);
        gen->append(&ch1, 1);
        gen->append(&ch2, 1);
    }
    gen->generate("1.wav");
    return 0;
}

int main()
{
    gen_sin();
    gen_test();
    return 0;
}
