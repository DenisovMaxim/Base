#ifndef SIGNALFILE_H
#define SIGNALFILE_H
#include <cstdint>
#include "complex.h"
#include <vector>

#include <iostream>

template<typename Type>
class SignalFile {

public:

    SignalFile ( int64_t fCen, int64_t fSam, uint64_t sz = 0, Type const*dt = 0);

    const uint32_t size() const;
    const int64_t  & freqCenter() const;
    int64_t const & freqSample() const;
    std::vector <Complex<Type>> & data();
    std::vector <Complex<Type>> const & data() const;
    Complex<Type> & data(uint64_t i);
    Complex<Type> const & data(uint64_t i) const;
    ~SignalFile ();


private:


    int64_t m_freqCenter;
    int64_t m_freqSample;
    std::vector <Complex<Type>> m_data;

};
template<typename Type>
SignalFile <Type> :: SignalFile ( int64_t fCen, int64_t fSam, uint64_t sz, Type const*dt) : m_freqCenter (fCen), m_freqSample(fSam) {
    m_data.resize(sz);
    if(dt!=nullptr){
        for (uint64_t i = 0; i < m_data.size(); i++) {
            m_data[i].re() = dt[2*i];
            m_data[i].im() = dt[2*i+1];
        }
    }
}

template<typename Type>
const uint32_t SignalFile<Type>::size() const {
    return m_data.size();
}

template<typename Type>
const int64_t  & SignalFile <Type> :: freqCenter() const {
    return m_freqCenter;
}

template<typename Type>
int64_t const & SignalFile <Type> :: freqSample() const {
    return m_freqSample;
}

template<typename Type>
SignalFile <Type> :: ~SignalFile () {

}

template<typename Type>
std::vector <Complex<Type>> & SignalFile <Type> :: data() {
    return m_data;
}


template<typename Type>
std::vector <Complex<Type>> const & SignalFile <Type> :: data() const {
    return m_data;
}

template<typename Type>
Complex<Type> & SignalFile <Type> :: data(uint64_t i){
    return m_data[i];
}

template<typename Type>
Complex<Type> const & SignalFile <Type> :: data(uint64_t i) const{
    return m_data[i];
}

#endif // SIGNALFILE_H
