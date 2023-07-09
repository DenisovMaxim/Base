#include <gtest/gtest.h>
#include "../demod.h"
#include "../reader.h"
#include <vector>
#include <fstream>

TEST( demodAM_test, first_test ) {

    Demodulation object;
}

TEST( demodAM_test, output_values ) {

    Reader reader;
    SignalFile< float > fileM = reader.readFile< float >( "data/test_data_for_deAM" );
    Demodulation test_obj;
    std::vector< float > data = test_obj.demodAM( fileM ); // vector for compare


    std::ifstream file( "data/TEST_deAM", std::fstream::binary );
    uint64_t size = data.size();
    std::vector< float > ex_data( size );
    for( uint64_t i = 0; i < size; i++ ) {
        file.read( reinterpret_cast< char* >( &ex_data[ i ] ), sizeof( float ) );
    }
    file.close();

    for( uint32_t i = 0; i < data.size(); ++i ) {
        ASSERT_EQ( data[ i ], ex_data[ i ] );
    }


}
