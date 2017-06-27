//
//  MSCAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 6. 8..
//

#ifndef MSCAlgorithm_hpp
#define MSCAlgorithm_hpp

#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "ReplacementAlgorithm.hpp"
using namespace std;

// Mutation Second Chance Algorithm
class MSCAlgorithm : public ReplacementAlgorithm {
private:
    const int PROBABILITY_OF_MUTATION = 1;
    
    vector<int> frame;
    vector<bool> referenceBits;
    int pointer = 0;
    
    void occurMutation();
    void increasePointer();
    bool check(int referencePage);
    void fetch(int referencePage);
    
public:
    MSCAlgorithm(int frameSize);
    virtual ~MSCAlgorithm();
    
    void init();
};

#endif /* MSCAlgorithm_hpp */
