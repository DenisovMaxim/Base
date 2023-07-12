#ifndef MOVEFREQ_H
#define MOVEFREQ_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdint>
#include <vector>
#include "complex.h"
#include "signalFile.h"

class MoveFreq {
public:
	template < typename Type >
	std::vector< Complex< Type > > ToZero( SignalFile< Type > const& sigFile );
private:
};

template < typename Type >
std::vector< Complex< Type > > MoveFreq::ToZero( SignalFile< Type > const& sigFile ) {
	uint64_t size = sigFile.size();
	std::vector< Complex< Type > > newData( size );
	uint64_t freqCen = sigFile.freqCenter();
	uint32_t freqSam = sigFile.freqSample();
	for( uint64_t i = 0; i < size; i++ ) {
		float newArg = sigFile.data( i ).arg() - i * freqCen * 2 * M_PI / freqSam;
		float absVal = sigFile.data( i ).abs();
		newData[ i ].re() = absVal * cos( newArg );
		newData[ i ].im() = absVal * sin( newArg );
	}
	return newData;
}

#endif