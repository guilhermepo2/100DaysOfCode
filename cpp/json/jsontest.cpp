#include <iostream>
#include "json/src/json.hpp"
#include <fstream>
using json = nlohmann::json;

int main()
{
  std::ifstream ifs("cards.json");
  json j(ifs);

  std::cout << "cards: " << j.size() << std::endl;
  
  /*
  for(json::iterator it = j.begin(); it != j.end(); ++it)
    {
      std::cout << it->dump(4) << std::endl;
      auto it1 = it["name"].get<std::string>();
      //std::cout << it1 << std::endl;
      //std::cout << it.key() << std::endl;
      break;
    }
  */

  return 0;
}
