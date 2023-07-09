#include <gtest/gtest.h>
#include "../demod.h"
#include "../reader.h"
#include <vector>
#include <fstream>

TEST( demodAM_test, first_test ) {

    Demodulation object;
}
// test_data_for_deAM
TEST( demodAM_test, output_values ) {

    Reader reader;
    SignalFile< double > fileM = reader.readFile< double >( "data/new_test_for_deAM" ); // что сравнить
    Demodulation test_obj;
    std::vector< double > data = test_obj.demodAM( fileM ); // vector for compare

// TEST_deAM
    std::ifstream file( "data/new_output_for_deAM", std::fstream::binary ); // с чем сравнить
    uint64_t size = data.size();
    std::vector< double > ex_data( size );
    for( uint64_t i = 0; i < size; i++ ) {
        file.read( reinterpret_cast< char* >( &ex_data[ i ] ), sizeof( double ) );
    }
    file.close();

    for( uint32_t i = 0; i < data.size(); ++i ) {
        ASSERT_EQ( data[ i ], ex_data[ i ] );
    }


}
