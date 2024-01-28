#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <memory>
#include <string>

class FileManager {
public:
    FileManager(const std::string& filePath);
    bool isOpen() const;
    std::string getFileContent() const;
    void reverseContent();
    int searchCount(const std::string& searchString) const;
    int replaceCount(const std::string& searchString, const std::string& replaceString);

private:
    std::unique_ptr<std::string> fileContent;
};

#endif
