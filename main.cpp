#include <iostream>
#include <memory>
#include "file_manager.h"

int main() {
    std::string filePath;
    std::cout << "Enter the path to the file: ";
    std::cin >> filePath;

    std::unique_ptr<FileManager> fileManager = std::make_unique<FileManager>(filePath);

    if (!fileManager->isOpen()) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }

    std::string searchString, replaceString;
    std::cout << "Enter the string to search: ";
    std::cin >> searchString;

    int searchCount = fileManager->searchCount(searchString);
    std::cout << "Search result: Found " << searchCount << " occurrences." << std::endl;

    std::cout << "Enter the string to replace: ";
    std::cin >> searchString;

    std::cout << "Enter the replacement string: ";
    std::cin >> replaceString;

    int replaceCount = fileManager->replaceCount(searchString, replaceString);
    std::cout << "Replacement result: Replaced " << replaceCount << " occurrences." << std::endl;

    std::cout << "File Content:\n" << fileManager->getFileContent() << std::endl;

    fileManager->reverseContent();
    std::cout << "Reversed File Content:\n" << fileManager->getFileContent() << std::endl;

    return 0;
}
