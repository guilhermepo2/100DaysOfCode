#ifndef FILE_HANDLER
#define FILE_HANDLER
#include <iostream>
#include <fstream>
#include <string>

class FileHandler
{
private:
  std::string mapUrl;
  char ** mapMatrix;
  int dimension;
public:
  FileHandler(std::string fileUrl);
  char getMatrixPosition(int i, int j);
  int getDimension();
};

#endif

#ifndef DEV_OPTIONS
#define DEV_OPTIONS

#define DEBUG 0

#endif
