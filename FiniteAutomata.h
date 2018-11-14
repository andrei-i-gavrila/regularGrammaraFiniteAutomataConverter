//
// Created by agavrila on 2018-11-12.
//

#ifndef REFALFTC_FINITEAUTOMATA_H
#define REFALFTC_FINITEAUTOMATA_H


#include <unordered_set>
#include <vector>
#include <ostream>
#include "streamOps.h"

class FiniteAutomata {
    std::unordered_set<char> states;
    std::unordered_set<char> terminals;
    std::vector<std::pair<std::pair<char, char>, char>> transitions;
    std::unordered_set<char> finalStates;
    char initialState;
public:

    FiniteAutomata() = default;

    FiniteAutomata(const std::vector<char>& states, const std::vector<char>& terminals, const std::vector<std::pair<std::pair<char, char>, char>>& transitions, const std::vector<char>& finalStates, char initialState) :
            states{states.begin(), states.end()}, terminals{terminals.begin(), terminals.end()}, transitions{transitions.begin(), transitions.end()}, finalStates{finalStates.begin(), finalStates.end()}, initialState{initialState} {

    }

    const std::unordered_set<char>& getStates() const {
        return states;
    }

    const std::unordered_set<char>& getTerminals() const {
        return terminals;
    }

    void setTerminals(const std::unordered_set<char>& terminals) {
        FiniteAutomata::terminals = terminals;
    }

    void setStates(const std::unordered_set<char>& states) {
        FiniteAutomata::states = states;
    }

    const std::vector<std::pair<std::pair<char, char>, char>>& getTransitions() const {
        return transitions;
    }

    void setTransitions(const std::vector<std::pair<std::pair<char, char>, char>>& transitions) {
        FiniteAutomata::transitions = transitions;
    }

    const std::unordered_set<char>& getFinalStates() const {
        return finalStates;
    }

    void setFinalStates(const std::unordered_set<char>& finalStates) {
        FiniteAutomata::finalStates = finalStates;
    }

    char getInitialState() const {
        return initialState;
    }


    void setInitialState(char initialState) {
        FiniteAutomata::initialState = initialState;
    }


    friend std::ostream& operator<<(std::ostream& os, const FiniteAutomata& automata) {
        os << "states: " << automata.states << " terminals: " << automata.terminals << " transitions: " << automata.transitions << " finalStates: " << automata.finalStates << " initialState: "
           << automata.initialState;
        return os;
    }
};


#endif //REFALFTC_FINITEAUTOMATA_H
