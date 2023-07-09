#include <gtest/gtest.h>
#include "../reader.h"
#include "../demod.h"
#include <vector>
#include <fstream>


TEST( TestDemodFM, DemodFine ) {
	Reader fileFM;
	SignalFile< double > fileM = fileFM.readFile< double >( "data/testDataFM" );
	Demodulation demod;
	std::vector< double > data_ = demod.demodFM( fileM );  // vector
	std::ifstream file( "data/testDataDM", std::fstream::binary );
	uint64_t size = fileM.size();
	std::vector< double > data( size );
	for( uint64_t i = 0; i < size; i++ ) {
		file.read( reinterpret_cast< char* >( &data[ i ] ), sizeof( double ) );
	}
	file.close();
	for( uint64_t i = 0; i < size; i++ ) {
		ASSERT_NEAR( data_[ i ], data[ i ], 1e-5 );
	}
}

