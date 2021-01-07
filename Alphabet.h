#ifndef ALPHABET_H
#define ALPHABET_H

#include "Sequence.h"
#include "IDictionary.h"
#include "ISet.h"
#include <string>

void clearEnter(std::string &string){
    string = ' '+string+' ';
    while(string.find("  ") != -1){
        string.erase(string.find("  "), 1);
    }
    string.erase(0, 1);
    string.erase(string.length()-1, 1);
}

IDictionary<std::string, ISet<int>> alphabetBuild (std::string string, int wordsPerPage){
    clearEnter(string);
    string = string+' ';
    std::string word;
    auto res = new IDictionary<std::string, ISet<int>>();
    int wordCount = 0;
    while(!string.empty()){
        word = string.substr(0, string.find(' '));
        string = string.erase(0, string.find(' ')+1);
        if(res->ContainsKey(word))
            res->Get(word).Add(wordCount/wordsPerPage+1);
        else{
            auto set = ISet<int>([](int x, int y){return x>y;});
            set.Add(wordCount/wordsPerPage+1);
            res->Add(word, set);
        }
        wordCount++;
    }
    return *res;
}

#endif
