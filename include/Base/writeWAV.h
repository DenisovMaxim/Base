#ifndef WRITEWAV_H
#define WRITEWAV_H

#include <fstream>
#include <cstring>
#include <cstdint>
#include <vector>

#include <typeinfo>

namespace Base {

	struct WavHeader {
		char chankId[ 4 ]       { 'R', 'I', 'F', 'F' };
		uint32_t chankSize;
		char format[ 4 ]        { 'W', 'A', 'V', 'E' };
		char subchunk1Id[ 4 ]   { 'f', 'm', 't', ' ' };
		uint32_t subchunk1Size  { 16 };
		uint16_t audioFormat;
		uint16_t numChannels    { 1 };
		uint32_t sampleRate;
		uint32_t byteRate;
		uint16_t blockAlign;
		uint16_t bitPerSample;
		char subchunk2Id[ 4 ]   { 'd', 'a', 't', 'a' };
		uint32_t subchunk2Size;
	};

	class WriteWAV {
public:
		void writeSignal( const std::string& path, std::vector< float > const& data, uint32_t fs = 48000 );
		void writeSignal( const std::string& path, std::vector< int16_t > const& data, uint32_t fs = 48000 );
private:
		WavHeader CreateHeader( uint32_t size, uint16_t format, uint32_t sampleRate );
	};

	WavHeader WriteWAV::CreateHeader( uint32_t size, uint16_t format, uint32_t sampleRate ) {
		WavHeader header;
		header.audioFormat = format;
		uint16_t tSize = 0;
		switch( format ) {
		case 1: tSize = sizeof( uint16_t );
			break;
		case 3: tSize = sizeof( float );
			break;
		}
		header.sampleRate = sampleRate;
		header.subchunk2Size = size * tSize;
		header.chankSize = 36 + header.subchunk2Size;
		header.bitPerSample = tSize * 8;
		header.blockAlign = header.numChannels * tSize;
		header.byteRate = header.blockAlign * header.sampleRate;

		return header;
	}

	void WriteWAV::writeSignal( const std::string& path, std::vector< float > const& data, uint32_t fs ) {
		WavHeader header = CreateHeader( data.size(), 3, fs );
		std::ofstream file( path );
		file.write( ( char* )&( header ), sizeof( WavHeader ) );
		file.write( ( char* )( data.data() ), sizeof( float ) * data.size() );
		file.close();
	}

	void WriteWAV::writeSignal( const std::string& path, std::vector< int16_t > const& data, uint32_t fs ) {
		WavHeader header = CreateHeader( data.size(), 1, fs );
		std::ofstream file( path );
		file.write( ( char* )&( header ), sizeof( WavHeader ) );
		file.write( ( char* )( data.data() ), sizeof( int16_t ) * data.size() );
		file.close();
	}
}
#endif // WRITER_H
