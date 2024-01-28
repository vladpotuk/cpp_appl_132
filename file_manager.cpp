#include "file_manager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager(const std::string& filePath) : fileContent(std::make_unique<std::string>()) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            *fileContent += line + "\n";
        }
        file.close();
    }
}

bool FileManager::isOpen() const {
    return fileContent != nullptr && !fileContent->empty();
}

std::string FileManager::getFileContent() const {
    return *fileContent;
}

void FileManager::reverseContent() {
    std::string reversedContent;
    for (int i = fileContent->length() - 1; i >= 0; --i) {
        reversedContent += (*fileContent)[i];
    }
    *fileContent = reversedContent;
}

int FileManager::searchCount(const std::string& searchString) const {
    int count = 0;
    size_t pos = 0;
    while ((pos = fileContent->find(searchString, pos)) != std::string::npos) {
        count++;
        pos += searchString.length();
    }
    return count;
}

int FileManager::replaceCount(const std::string& searchString, const std::string& replaceString) {
    int count = 0;
    size_t pos = 0;
    while ((pos = fileContent->find(searchString, pos)) != std::string::npos) {
        fileContent->replace(pos, searchString.length(), replaceString);
        pos += replaceString.length();
        count++;
    }
    return count;
}
