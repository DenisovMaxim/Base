#include <gtest/gtest.h>
#include "../include/Base/writer.h"
#include <vector>
#include <fstream>

TEST( TestWriter, Creating ) {
	Writer fileWrite;
}

TEST( TestWriter, WriteFine ) {
	uint64_t size = 100000;
	std::vector< double > data_( size );
	for( uint64_t i = 0; i < size; i++ ) {
		data_[ i ] = ( size - i ) * i / size;
	}
	Writer fileWriter;
	fileWriter.writeFile( "data/dataWrite", data_, 1 );
	std::ifstream file( "data/dataWrite1.iqd", std::fstream::binary );
	std::vector< double > data( size );
	for( uint64_t i = 0; i < size; i++ ) {
		file.read( reinterpret_cast< char* >( &data[ i ] ), sizeof( double ) );
	}
	file.close();
	for( uint64_t i = 0; i < size; i++ ) {
		ASSERT_EQ( data_[ i ], data[ i ] );
	}
}