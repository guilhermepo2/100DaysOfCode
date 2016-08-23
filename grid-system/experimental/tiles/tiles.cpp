#include "tiles.hpp"

Tile::Tile(char letter, std::string image_url, int r_value, int g_value, int b_value)
{
  this->letter = letter;
  this->image_url = image_url;
  this->r_value = r_value;
  this->g_value = g_value;
  this->b_value = b_value;
}

char Tile::getLetter()
{
  return this->letter;
}

std::string Tile::getImageUrl()
{
  return this->image_url;
}

int Tile::getRValue()
{
  return this->r_value;
}

int Tile::getGValue()
{
  return this->g_value;
}

int Tile::getBValue()
{
  return this->b_value;
}
