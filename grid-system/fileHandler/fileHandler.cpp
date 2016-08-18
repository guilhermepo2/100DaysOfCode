#include "fileHandler.hpp"

FileHandler::FileHandler(std::string fileUrl)
{
  std::cout << fileUrl << std::endl;
  this->mapUrl = fileUrl;
  std::ifstream mapFile(fileUrl);

  std::string line;
  if(!mapFile.good())
    {
      std::cout << "Error opening: " << this->mapUrl << "... are you sure this is a file?" << std::endl;
      exit(0);
    }

  if(mapFile.is_open())
    {
      while(getline(mapFile, line))
	{
	  std::cout << line << std::endl;
	} 
    }

  mapFile.close();
}
