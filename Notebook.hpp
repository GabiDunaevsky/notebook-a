#include "Direction.hpp"
#include <string>
#include <map>

using namespace std;
namespace ariel{
    const short maxColLen = 100;

    class Notebook{
        map<string,char>loc;
        public:

        Notebook();
        ~Notebook();

        static void write (int page,int row,int column,Direction dir , string const & word);
        

        static string read(int page,int row,int column, Direction dir, int len);
        
        static void erase(int page,int row, int column, Direction dir,int len);

        void show(int page);

         
    };
}

