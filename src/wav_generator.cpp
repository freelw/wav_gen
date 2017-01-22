#include "wav_generator.h"
#include <string.h>
#include <stdio.h>

int wav_generator::append(char *buffer, int size)
{
    for (int i = 0; i < size; ++ i) {
        m_data.push_back(buffer[i]);
    }
    return 0;
}

int wav_generator::generate(const char *file_name)
{
    generate_fmt();
    generate_data_header();
    generate_riff();
    FILE *fp = fopen(file_name, "wb");
    fwrite(m_riff.data(), m_riff.size(), 1, fp);
    fwrite(m_fmt.data(), m_fmt.size(), 1, fp);
    fwrite(m_data_header.data(), m_data_header.size(), 1, fp);
    fwrite(m_data.data(), m_data.size(), 1, fp);
    fclose(fp);
    return 0;
}

int wav_generator::generate_riff()
{
    long size = m_fmt.size() + m_data_header.size() + m_data.size();
    char riff_buffer[12] = {0};
    memcpy(riff_buffer, "RIFF....WAVE", 12);
    memcpy(riff_buffer+4, &size, 4);
    m_riff.assign(riff_buffer, riff_buffer+12);
    return 0;
}

int wav_generator::generate_fmt()
{
    const char *id = "fmt ";
    long size = 16;
    short format_tag = 1;
    short channels = 1;
    long samples_per_sec = 44100;
    short bits_per_sample = 8;
    short block_align = bits_per_sample*channels/8; 
    long bytes_per_sec = samples_per_sec*block_align;
    char fmt_buffer[24] = {0};

    memcpy(fmt_buffer, id, 4);
    memcpy(fmt_buffer+4, &size, 4);
    memcpy(fmt_buffer+8, &format_tag, 2);
    memcpy(fmt_buffer+10, &channels, 2);
    memcpy(fmt_buffer+12, &samples_per_sec, 4);
    memcpy(fmt_buffer+16, &bytes_per_sec, 4);
    memcpy(fmt_buffer+20, &block_align, 2);
    memcpy(fmt_buffer+22, &bits_per_sample, 2);
    m_fmt.assign(fmt_buffer, fmt_buffer+24);
    return 0;
}

int wav_generator::generate_data_header()
{
    const char *id = "data";
    long size = m_data.size();
    char data_header_buffer[8] = {0};
    memcpy(data_header_buffer, id, 4);
    memcpy(data_header_buffer+4, &size, 4);
    m_data_header.assign(data_header_buffer, data_header_buffer+8);
    return 0;
}

