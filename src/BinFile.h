#pragma once

#include <string>
#include <fstream>
#include <vector>

void write(const std::string& fileName, std::vector<uint_fast8_t> writableData);

std::vector<uint_fast8_t> read(const std::string& fileName);
