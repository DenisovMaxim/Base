#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <cstring>
#include "signalFile.h"
#include <cstdint>
#include <vector>
#include <typeinfo>

namespace Base {

	class Writer {

public:
		/**
		 * @brief writeFile запись в файл
		 * @param data ссылка на вектор
		 * @param fd частота дискретизации
		 * @param ext используемый тип данных [s - short; f - float]
		 */
		template < typename Type >
		void writeFile( const std::string& path, std::vector< Type > const& data, uint32_t fd );


private:

	};


	template < typename Type >
	void Writer::writeFile( const std::string& path, std::vector< Type > const& data, uint32_t fd ) {
		std::string ext = typeid( data[ 0 ] ).name();
		uint64_t size = data.size();
		std::string path_ = ( path + std::to_string( fd ) + ".iq" + ext );
		std::ofstream file( path_ );
		file.write( ( char* )( data.data() ), sizeof( Type ) * size );

		file.close();

	}

}

#endif // WRITER_H
