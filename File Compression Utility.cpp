#include <iostream>
#include <fstream>
#include <vector>
#include <zlib.h>

void compressFile(const std::string &source, const std::string &destination) {
    std::ifstream inputFile(source, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Could not open source file for reading: " << source << std::endl;
        return;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(inputFile)), {});
    inputFile.close();

    uLongf compressedSize = compressBound(buffer.size());
    std::vector<Bytef> compressedData(compressedSize);

    if (compress(compressedData.data(), &compressedSize, reinterpret_cast<const Bytef*>(buffer.data()), buffer.size()) != Z_OK) {
        std::cerr << "Error compressing file: " << source << std::endl;
        return;
    }

    std::ofstream outputFile(destination, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Could not open destination file for writing: " << destination << std::endl;
        return;
    }
    outputFile.write(reinterpret_cast<const char*>(compressedData.data()), compressedSize);
    outputFile.close();

    std::cout << "File compressed successfully: " << destination << std::endl;
}

void decompressFile(const std::string &source, const std::string &destination) {
    std::ifstream inputFile(source, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Could not open source file for reading: " << source << std::endl;
        return;
    }

    std::vector<char> compressedData((std::istreambuf_iterator<char>(inputFile)), {});
    inputFile.close();

    uLongf decompressedSize = compressedData.size() * 4; // Estimate size for decompression
    std::vector<Bytef> decompressedData(decompressedSize);

    while (uncompress(decompressedData.data(), &decompressedSize, reinterpret_cast<const Bytef*>(compressedData.data()), compressedData.size()) == Z_BUF_ERROR) {
        decompressedSize *= 2; // Increase size and try again
        decompressedData.resize(decompressedSize);
    }

    std::ofstream outputFile(destination, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Could not open destination file for writing: " << destination << std::endl;
        return;
    }
    outputFile.write(reinterpret_cast<const char*>(decompressedData.data()), decompressedSize);
    outputFile.close();

    std::cout << "File decompressed successfully: " << destination << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <compress|decompress> <source> <destination>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string source = argv[2];
    std::string destination = argv[3];

    if (mode == "compress") {
        compressFile(source, destination);
    } else if (mode == "decompress") {
        decompressFile(source, destination);
    } else {
        std::cerr << "Unknown mode: " << mode << std::endl;
        return 1;
    }

    return 0;
}
