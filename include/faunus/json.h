#ifndef FAU_JSON
#define FAU_JSON
#include <faunus/common.h>
#include <faunus/json.hpp>

namespace Faunus {

  typedef nlohmann::json Tmjson;

  inline Tmjson openjson(const string &file) {
    Tmjson js;
    std::ifstream f(file.c_str());
    if (f) {
      try {
        js << f;
      } 
      catch (...) {
        std::cerr << "Error loading json file '" << file
          << "'. Carefully check the syntax." << endl;
        std::exit(1);
      }
    }
    return js;
  }
}//namespace
#endif

