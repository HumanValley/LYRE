#include "./utils.hpp"

char *readFile(const std::string path) {

    char *          buffer;
	std::streampos	fileSize;
    std::fstream    fileStream(path);

    if (!fileStream.good())
        throw std::runtime_error("Error: file not found");

	fileSize = getFileSize(fileStream);
	buffer = new char[fileSize];

    fileStream.read(buffer, fileSize);
    fileStream.close();

    return buffer;
}

std::streampos getFileSize(std::fstream &fileStream) {

	std::streampos fileSize;

	fileStream.seekg(0, std::ios::end);
	fileSize = fileStream.tellg();
	fileStream.seekg(0, std::ios::beg);

	return fileSize;
}