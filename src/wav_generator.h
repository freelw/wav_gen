#ifndef WAV_GENERATOR_H
#define WAV_GENERATOR_H

#include <vector>

class wav_generator
{

public:
    wav_generator(short format_tag = 1, short channels = 1, long samples_per_sec = 44100, short bits_per_sample = 8) :
        m_format_tag(format_tag),
        m_channels(channels),
        m_samples_per_sec(samples_per_sec),
        m_bits_per_sample(bits_per_sample)
    {}
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

    short m_format_tag;
    short m_channels;
    long m_samples_per_sec;
    short m_bits_per_sample;
};

#endif
