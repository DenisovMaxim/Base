#include <gtest/gtest.h>
#include "base/reader.h"
#include "base/signalFile.h"
#include "base/complex.h"

using namespace Base;

TEST( reader_test, test_Fd ) {

	Reader test_obj;
    std::string ds = "data/test_data_for_reader_Fd";

	try {
		SignalFile< float > file = test_obj.readFile< float >( ds );


	} catch( std::runtime_error& e ) {

		ASSERT_STREQ( e.what(), "invalid sample frequency value" ) << "something wrong\n";

	}
}
TEST( reader_test, test_Fc ) {

	Reader test_obj;
    std::string ds = "data/test_data_for_reader_Size";

	try {
		SignalFile< float > file = test_obj.readFile< float >( ds );


	} catch( std::runtime_error& e ) {

		ASSERT_STREQ( e.what(), "zero data size value" ) << "something wrong\n";

	}
}
TEST( reader_test, test_open ) {

	Reader test_obj;
	std::string ds = "data/reader_test/test_data_for_reader_x";

	try {
		SignalFile< float > file = test_obj.readFile< float >( ds );


	} catch( std::runtime_error& e ) {

		ASSERT_STREQ( e.what(), "cant open file " ) << "something wrong\n";

	}
}

