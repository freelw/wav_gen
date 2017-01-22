#include <stdio.h>
#include "wav_generator.h"

int main()
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
