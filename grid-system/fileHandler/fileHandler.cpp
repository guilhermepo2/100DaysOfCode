#include "fileHandler.hpp"
#include <algorithm>

FileHandler::FileHandler(std::string fileUrl)
{
  #if DEBUG
  std::cout << fileUrl << std::endl;
  #endif
  
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
      getline(mapFile, line);
      int actualRow = 0;
      line.erase(std::remove(line.begin(), line.end(), ' ')
		 ,line.end());
      this->dimension = line.size();
      this->mapMatrix = new char*[line.size()];
      
      this->mapMatrix[0] = new char[line.size()];
      for(int i = 0; i < line.size(); i++) this->mapMatrix[0][i] = line[i];
      actualRow++;
      
      while(getline(mapFile, line))
	{
	  line.erase(std::remove(line.begin(), line.end(), ' '),
		     line.end());
	  this->mapMatrix[actualRow] = new char[line.size()];
	  for(int i = 0; i < line.size(); i++) this->mapMatrix[actualRow][i] = line[i];
	  actualRow++;
	}

      #if DEBUG
      // printing matrix so you can see it
      for(int i = 0; i < line.size(); i++)
	{
	  for(int j = 0; j < line.size(); j++)
	    {
	      std::cout << this->mapMatrix[i][j] << " ";
	    }
	  std::cout << std::endl;
	}
      #endif
    }

  mapFile.close();
}


char FileHandler::getMatrixPosition(int i, int j)
{
  if(i < 0 || i >= this->dimension || j < 0 || j >= this->dimension)
    {
      std::cout << "This is not how Matrix works." << std::endl;
    }

  return this->mapMatrix[i][j];
}

int FileHandler::getDimension()
{
  return this->dimension;
}
