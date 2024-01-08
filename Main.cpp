#include "utils.h"
//#include "./Classes/Commands.h"
#include "Terminal.h"
#include "Interface.h"


using namespace std;
using namespace term;


int main() {

    Terminal &t = Terminal::instance();

    for(int i=1; i<20; i++) t.init_color(i, i, 0);

    t << move_to(4,2) << set_color(5) << "SIMULADOR-HABITACAO";
    t << move_to(4,29) << set_color(5) << "CMD";
    t << move_to(86,2) << set_color(5) << "INFO";

    Interface a;
    a.leComando();

    t.getchar();



    return 0;
}
