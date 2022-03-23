#include "Notebook.hpp"
#include <stdexcept>
using namespace std;

namespace ariel{

    void Notebook::write(int page, int row, int column, Direction direction, string const& sentece){
        
        if(page < 0 || row < 0 || column < 0){
             throw runtime_error("page, row and column has to be non negative");
        }
    }
    string Notebook::read(int page, int row, int column, Direction direction, int chars_to_read){

        if(page < 0 || row < 0 || column < 0 || chars_to_read < 0){
             throw runtime_error("page, row, column and chars_to_read has to be non negative");
        }
        return "all good";
    }
    void Notebook::erase(int page, int row, int column, Direction direction, int chars_to_erase){

        if(page < 0 || row < 0 || column < 0 || chars_to_erase < 0){
             throw runtime_error("page, row, column and chars_to_erase has to be non negative");
        }
    }
    void Notebook::show(int page){
        if(page < 0){
            throw runtime_error("page has to be non negative");
        }
    }
}