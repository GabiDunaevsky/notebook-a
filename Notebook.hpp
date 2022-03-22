#include "Direction.hpp"
#include <string>

using namespace std;
namespace ariel{
    const short maxColLen = 100;

    class Notebook{

        public:

        Notebook();
        ~Notebook();

        void write (int page,int row,int column,Direction dir , string word);
        

        string read(int page,int row,int column, Direction dir, int len);
        
        void erase(int page,int row, int column, Direction dir,int len);

        void show(int page);

         bool checkNegativity(int j);
    };
}

