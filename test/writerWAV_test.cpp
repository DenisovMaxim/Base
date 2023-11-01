#include <gtest/gtest.h>
#include "../include/Base/writeWAV.h"
#include <vector>
#include <fstream>

using namespace Base;

TEST( TestWriteWAV, WriteWAVFine ) {
	std::ifstream file( "data/dataWAV44100.iqf", std::fstream::binary );
	uint32_t size = 0;
	file.seekg( 0, std::ios::end );
	size = file.tellg() / sizeof( float );
	file.seekg( 0, std::ios::beg );

	std::vector< float > data( size );
	file.read( ( char* )( data.data() ), sizeof( float ) * size );
	file.close();

	WriteWAV writeWave;
	writeWave.writeSignal( "data/testWAV.wav", data, 44100 );

	file.open( "data/testWAV.wav", std::fstream::binary );
	file.seekg( 40, std::ios::beg );
	uint32_t bSize = 0;
	file.read( ( char* )( &bSize ), sizeof( uint32_t ) );
	size = bSize / sizeof( float );

	for( uint32_t i = 0; i < size; i++ ) {
		float tmp;
		file.read( reinterpret_cast< char* >( &tmp ), sizeof( float ) );
		ASSERT_EQ( tmp, data[ i ] );
	}
	file.close();
}
