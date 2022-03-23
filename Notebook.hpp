#include <string>
#include "Direction.hpp"

namespace ariel{

    class Notebook{
        public:
        Notebook(){
            return;
        }
        static void write(int page, int row, int column, Direction direction, std::string const& sentece);
        static std::string read(int page, int row, int column, Direction direction, int chars_to_read);
        static void erase(int page, int row, int column, Direction direction, int chars_to_erase);
        static void show(int page);

    };
}