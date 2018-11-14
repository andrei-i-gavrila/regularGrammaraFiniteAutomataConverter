//
// Created by agavrila on 2018-11-12.
//

#ifndef REFALFTC_CONVERTER_H
#define REFALFTC_CONVERTER_H


#include "Grammar.h"
#include "FiniteAutomata.h"

using namespace std::string_literals;

class Converter {


public:
    auto toFiniteAutomata(const Grammar& grammar) const -> FiniteAutomata {
        if (not grammar.isRegular()) {
            throw std::logic_error{"cannot convert"};
        }

        auto newState = 'A';
        auto q0 = grammar.getStartingSymbol();
        auto Q = std::vector<char>{grammar.getNonTerminals().begin(), grammar.getNonTerminals().end()};
        auto sigma = std::vector<char>{grammar.getTerminals().begin(), grammar.getTerminals().end()};
        auto F = std::vector<char>{};
        auto transitions = std::vector<std::pair<std::pair<char, char>, char>>{};
        for (const auto& production: grammar.getProductions()) {
            if (production.second.length() == 1) {
                if (production.second[0] == EPSILON) {
                    F.push_back(production.first);
                }

                while (grammar.getNonTerminals().find(newState) != grammar.getNonTerminals().end()) {
                    newState++;
                }

                transitions.emplace_back(std::make_pair(production.first, production.second[0]), newState);
                F.push_back(newState);
                Q.push_back(newState);
            }
            if (production.second.length() == 2) {
                transitions.emplace_back(std::make_pair(production.first, production.second[0]), production.second[1]);
            }
        }


        return FiniteAutomata{Q, sigma, transitions, F, q0};
    }

    auto toGrammar(const FiniteAutomata& finiteAutomata) const -> Grammar {
        auto N = std::vector<char>{finiteAutomata.getStates().begin(), finiteAutomata.getStates().end()};
        auto sigma = std::vector<char>{finiteAutomata.getTerminals().begin(), finiteAutomata.getTerminals().end()};
        auto S = finiteAutomata.getInitialState();
        auto P = std::vector<std::pair<char, std::string>>{};

        for (const auto& transition : finiteAutomata.getTransitions()) {
            if (finiteAutomata.getFinalStates().find(transition.second) != finiteAutomata.getFinalStates().end()) {
                P.emplace_back(transition.first.first, ""s + transition.first.second);
            }
            P.emplace_back(transition.first.first, ""s + transition.first.second + transition.second);
        }


        return Grammar{N, sigma, P, S};
    }

};


#endif //REFALFTC_CONVERTER_H
