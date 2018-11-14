#include <iostream>
#include "Grammar.h"
#include "FiniteAutomata.h"
#include "Converter.h"




int main() {

    Grammar grammar{{'A', 'B', 'S'}, {'a', 'b', '#'}, {{'S', "aB"}, {'A', "a"}, {'B', "bA"}, {'S', "#"}}, 'S'};
    FiniteAutomata finiteAutomata{{'A', 'B', 'S', 'C'}, {'0', '1', '2'}, {{{'A', '0'}, 'B'}, {{'C', '1'}, 'A'}, {{'S', '2'}, 'A'}}, {'B'}, 'S'};

    std::cout << grammar.isRegular() << '\n';

    Converter converter{};
    std::cout << grammar << "\n" << finiteAutomata << "\n\n\n";


    std::cout << grammar << "\n" << converter.toGrammar(converter.toFiniteAutomata(grammar)) << "\n\n";
    std::cout << finiteAutomata << "\n" << converter.toFiniteAutomata(converter.toGrammar(finiteAutomata)) << "\n";





    return 0;
}
