
#ifndef READER_H
#define READER_H
#include <fstream>
#include <cstring>
#include "signalFile.h"
#include <cstdint>

class Reader {
public:
    template<typename Type>
    SignalFile<Type> readFile(std::string const & filename);
private:
};

template<typename Type>
SignalFile<Type> Reader::readFile (std::string const & filename) {

    std :: ifstream file (filename, std::fstream::binary);
    if(!file.is_open()){
        throw std::runtime_error("cant open file " + filename);
    }
    int64_t freqCen;
    uint32_t freqSam;
    uint64_t size;

    file.read(reinterpret_cast<char*>(&freqCen), sizeof(int64_t));
    file.read(reinterpret_cast<char*>(&freqSam), sizeof(uint32_t));
    file.read(reinterpret_cast<char*>(&size), sizeof(uint64_t));

    if(freqCen<0){
        throw std::runtime_error("invalid center frequency value");
    }
    if(freqSam<=0){
        throw std::runtime_error("invalid sample frequency value");
    }
    if(size==0){
        throw std::runtime_error("zero data size value");
    }
    SignalFile<Type> signalF(freqCen,freqSam,size);
    for (uint64_t i = 0; i < size; i++) {
        file.read(reinterpret_cast<char*>(&(signalF.data(i).re())), sizeof(Type));
        file.read(reinterpret_cast<char*>(&(signalF.data(i).im())), sizeof(Type));
    }
    file.close();
    return  std::move(signalF);

}



#endif // READER_H
