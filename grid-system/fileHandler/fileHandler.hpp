#ifndef FILE_HANDLER
#define FILE_HANDLER
#include <iostream>
#include <fstream>
#include <string>


class FileHandler
{
private:
  std::string mapUrl;
public:
  FileHandler(std::string fileUrl);
};

#endif
