#include  <ostream>
#include <iostream>
#include  <fstream>

namespace tq84 {

class debug {

  public:
    debug(const std::string& filename);
   ~debug();

    void log(const std::string& text);

    class indent_ {
      friend debug;
      private:
        indent_(debug& dbg);
        debug& debug_;

      public:
       ~indent_();

    };

    indent_ indent(const std::string& text);

  private:

    std::ostream* stream_out = nullptr;

    int indent_level = 0;

    void print_line(const std::string& text);
};


}
