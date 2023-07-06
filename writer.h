#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <cstring>
#include "signalFile.h"
#include <cstdint>
#include <vector>

class Writer {

public:
    template<typename Type>
    void writeFile (std::vector <Type> const & data, int64_t fd, const std::string & ext); // ext - тип данных [s - short; f - float]


private:

};


template<typename Type>
void Writer :: writeFile (std::vector <Type> const & data, int64_t fd, const std::string &ext)
{
    uint32_t size = data.size();
    std::string path = ("/home/ann/WORK/work_mtlb/ourfile" + std::to_string(fd)+ ".iq" + ext);

    std::ofstream OURfile (path);
    for (uint32_t i = 0; i < size ; i++)
    {
        OURfile.write((char*)&(data[i]),sizeof(Type));

    }

    OURfile.close();



}









#endif // WRITER_H
