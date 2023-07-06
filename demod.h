#ifndef DEMOD_H
#define DEMOD_H
#include <vector>
#include "signalFile.h"
#include "complex.h"
#define _USE_MATH_DEFINES
#include <cmath>

class Demodulation {

public:
    template<typename Type>
    std::vector <Type> demodAM (SignalFile<Type> const & sigFile);
    template<typename Type>
    std::vector<Type> demodFM(SignalFile<Type> const & sigFile);
private:
};

template<typename Type>
std::vector <Type> Demodulation::demodAM (SignalFile<Type> const & sigFile){
    uint32_t size = sigFile.size();
    std::vector <Type> data (size);
    for(uint32_t i = 0; i < size; i++)
    {
        data[i] = sigFile.data(i).abs();
    }
    return std::move(data);
}

template<typename Type>
std::vector<Type> Demodulation::demodFM (SignalFile<Type> const & sigFile){
    uint32_t size = sigFile.size();
    int64_t fCen = sigFile.freqCenter();
    int64_t fSam = sigFile.freqSample();
    std::vector<Type> data(size);
    for(uint32_t i = 0; i < size; i++){
        data[i]=sigFile.data(i).arg();
    }
    for(uint32_t i = 0; i < size-1; i++){
        Type dif = data[i+1]-data[i];
        if(dif > M_PI) dif-=2*M_PI;
        if(dif < -M_PI) dif+=2*M_PI;
        data[i]=dif*fSam-fCen*2*M_PI;
    }
    data[size-1]=0;
    return std::move(data);
}

#endif // DEMOD_H
