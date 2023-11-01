#ifndef SIGNALFILE_H
#define SIGNALFILE_H
#include <cstdint>
#include "complex.h"
#include <vector>

#include <iostream>

namespace Base {

	template < typename Type >
	class SignalFile {

public:

		SignalFile( uint64_t fCen, uint32_t fSam, uint64_t sz = 0, Type const* dt = 0 );

		uint64_t size() const;
		uint64_t const& freqCenter() const;
		uint32_t const& freqSample() const;
		std::vector< Base::Complex< Type > >& data();
		std::vector< Base::Complex< Type > > const& data() const;
		Base::Complex< Type >& data( uint64_t i );
		Base::Complex< Type > const& data( uint64_t i ) const;
		~SignalFile();


private:


		uint64_t m_freqCenter;
		uint32_t m_freqSample;
		std::vector< Base::Complex< Type > > m_data;

	};
	template < typename Type >
	SignalFile< Type >::SignalFile( uint64_t fCen, uint32_t fSam, uint64_t sz, Type const* dt ) : m_freqCenter( fCen ), m_freqSample( fSam ) {
		m_data.resize( sz );
		if( dt != nullptr ) {
			for( uint64_t i = 0; i < m_data.size(); i++ ) {
                m_data[ i ].re = dt[ 2 * i ];
                m_data[ i ].im = dt[ 2 * i + 1 ];
			}
		}
	}

	template < typename Type >
	uint64_t SignalFile< Type >::size() const {
		return m_data.size();
	}

	template < typename Type >
	uint64_t const& SignalFile< Type >::freqCenter() const {
		return m_freqCenter;
	}

	template < typename Type >
	uint32_t const& SignalFile< Type >::freqSample() const {
		return m_freqSample;
	}

	template < typename Type >
	SignalFile< Type >::~SignalFile() {

	}

	template < typename Type >
	std::vector< Base::Complex< Type > >& SignalFile< Type >::data() {
		return m_data;
	}


	template < typename Type >
	std::vector< Base::Complex< Type > > const& SignalFile< Type >::data() const {
		return m_data;
	}

	template < typename Type >
	Base::Complex< Type >& SignalFile< Type >::data( uint64_t i ) {
		return m_data[ i ];
	}

	template < typename Type >
	Base::Complex< Type > const& SignalFile< Type >::data( uint64_t i ) const {
		return m_data[ i ];
	}
}
#endif // SIGNALFILE_H
