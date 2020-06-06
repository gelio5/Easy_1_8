#include "BinFile.h"

void write(const std::string& fileName, std::vector<uint_fast8_t> writableData)
{
    std::ofstream output;
    output.open(fileName, std::ios::binary);

    if (writableData.begin() == writableData.end())
        throw std::length_error("Writable data is empty");

    for (auto position : writableData)
        output.write((char *)(&position), sizeof(position));

    output.close();
}

std::vector<uint_fast8_t> read(const std::string& fileName)
{
    std::ifstream input;
    input.open(fileName, std::ios::binary);
    if (!input)
        throw std::invalid_argument("File with name \"" + fileName + "\" does not exist");
    struct stat fileInfo{};
    stat(fileName.c_str(), &fileInfo);
    int fileSize = fileInfo.st_size;
    std::vector<uint_fast8_t> readableData(fileSize);
    for (auto& position : readableData)
        input >> position;
    input.close();
    return readableData;
}
