#ifndef MOVEFREQ_H
#define MOVEFREQ_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdint>
#include <vector>
#include "complex.h"
#include "signalFile.h"

namespace Base {

	class MoveFreq {
public:
		template < typename Type >
		std::vector< Base::Complex< Type > > ToZero( Base::SignalFile< Type > const& sigFile );
		template < typename Type >
		void ToZero( Base::Complex< Type >* dataIn, Base::Complex< Type >* dataOut, uint32_t N, uint32_t Fs, uint32_t Fc );
private:
	};

	template < typename Type >
	std::vector< Base::Complex< Type > > MoveFreq::ToZero( Base::SignalFile< Type > const& sigFile ) {
		uint64_t size = sigFile.size();
		std::vector< Base::Complex< Type > > newData( size );
		uint64_t freqCen = sigFile.freqCenter();
		uint32_t freqSam = sigFile.freqSample();
		for( uint64_t i = 0; i < size; i++ ) {
			float newArg = sigFile.data( i ).arg() - i * freqCen * 2 * M_PI / freqSam;
			float absVal = sigFile.data( i ).abs();
            newData[ i ].re = absVal * cos( newArg );
            newData[ i ].im = absVal * sin( newArg );
		}
		return newData;
	}

	template < typename Type >
	void MoveFreq::ToZero( Base::Complex< Type >* dataIn, Base::Complex< Type >* dataOut, uint32_t N, uint32_t Fs, uint32_t Fc ) {
		for( uint64_t i = 0; i < N; i++ ) {
			float newArg = dataIn[ i ].arg() - i * Fc * 2 * M_PI / Fs;
			float absVal = dataIn[ i ].abs();
            dataOut[ i ].re = absVal * cos( newArg );
            dataOut[ i ].im = absVal * sin( newArg );
		}
	}

}
#endif
