//
// Created by agavrila on 2018-11-12.
//

#ifndef REFALFTC_GRAMMAR_H
#define REFALFTC_GRAMMAR_H


static const char EPSILON = '#';

#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "streamOps.h"
#include <ostream>


class Grammar {
    std::unordered_set<char> terminals;
    std::unordered_set<char> nonTerminals;
    std::unordered_multimap<char, std::string> productions;
    char startingSymbol;

public:


    Grammar() = default;

    Grammar(const std::vector<char>& nonTerminals, const std::vector<char>& terminals, const std::vector<std::pair<char, std::string>>& productions, char startingSymbol) :
            terminals{terminals.begin(), terminals.end()}, nonTerminals{nonTerminals.begin(), nonTerminals.end()}, productions{productions.begin(), productions.end()}, startingSymbol{startingSymbol} {
        if (terminals.size() != this->terminals.size()) {
            throw std::logic_error{"duplicate terminals"};
        };

        for (auto terminal: terminals) {
            if (isupper(terminal)) {
                throw std::logic_error{"all terminals must be lowercase"};
            };
        }

        if (nonTerminals.size() != this->nonTerminals.size()) {
            throw std::logic_error{"duplicate nonTerminals"};
        };


        for (auto nonTerminal: nonTerminals) {
            if (islower(nonTerminal)) {
                throw std::logic_error{"all nonTerminals must be uppercase"};
            };
        }

        if (this->nonTerminals.find(startingSymbol) == this->nonTerminals.end()) {
            throw std::logic_error{"starting symbol is not a nonTerminal"};
        };

        for (const auto& production: productions) {
            if (this->nonTerminals.find(production.first) == this->nonTerminals.end()) {
                throw std::logic_error{"invalid prod"};
            }
            if (production.second.length() == 0) {
                throw std::logic_error{"bla"};
            };
        }
    }

    const std::unordered_set<char>& getTerminals() const {
        return terminals;
    }

    void setTerminals(const std::unordered_set<char>& terminals) {
        Grammar::terminals = terminals;
    }

    const std::unordered_set<char>& getNonTerminals() const {
        return nonTerminals;
    }

    void setNonTerminals(const std::unordered_set<char>& nonTerminals) {
        Grammar::nonTerminals = nonTerminals;
    }

    const std::unordered_multimap<char, std::string>& getProductions() const {
        return productions;
    }

    void setProductions(const std::unordered_multimap<char, std::string>& productions) {
        Grammar::productions = productions;
    }

    char getStartingSymbol() const {
        return startingSymbol;
    }

    void setStartingSymbol(char startingSymbol) {
        Grammar::startingSymbol = startingSymbol;
    }

    auto isRegular() const -> bool {
        auto sGoesEps = false;
        auto sOnTheLeft = false;

        for (const auto& production : productions) {
            if (production.first == startingSymbol && production.second[0] == EPSILON) {
                sGoesEps = true;
            }

            if (production.second.length() > 2) {
                return false;
            }

            if (production.second.find(startingSymbol) != std::string::npos) {
                sOnTheLeft = true;
            }
            if (terminals.find(production.second[0]) == terminals.end()) {
                return false;
            }

            if (production.second.length() == 2 && nonTerminals.find(production.second[1]) == nonTerminals.end()) {
                return false;
            }
        }

        return !(sGoesEps && sOnTheLeft);
    }

    friend std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
        os << "terminals: " << grammar.terminals << " nonTerminals: " << grammar.nonTerminals << " productions: " << grammar.productions << " startingSymbol: " << grammar.startingSymbol;
        return os;
    }

};




#endif //REFALFTC_GRAMMAR_H
