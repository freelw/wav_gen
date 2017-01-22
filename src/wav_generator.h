#ifndef WAV_GENERATOR_H
#define WAV_GENERATOR_H

#include <vector>

class wav_generator
{

public:
    wav_generator() {}
    ~wav_generator() {}
    int append(char *buffer, int size);
    int generate(const char *file_name);

private:
    int generate_riff();
    int generate_fmt();
    int generate_data_header();

private:
    std::vector<char> m_riff;
    std::vector<char> m_fmt;
    std::vector<char> m_data_header;
    std::vector<char> m_data;
};

#endif
