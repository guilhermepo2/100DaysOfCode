#ifndef TILES_HEADER
#define TILES_HEADER
#include <iostream>


class Tile
{
private:
  char letter;
  std::string image_url;
  int r_value;
  int g_value;
  int b_value;

public:
  Tile(char letter, std::string image_url, int r_value, int g_value, int b_value);
  char getLetter();
  std::string getImageUrl();
  int getRValue();
  int getGValue();
  int getBValue();
};

#endif
