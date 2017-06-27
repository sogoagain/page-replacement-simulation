//
//  RANDAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 20..
//

#ifndef RANDAlgorithm_hpp
#define RANDAlgorithm_hpp

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ReplacementAlgorithm.hpp"
using namespace std;

class RANDAlgorithm : public ReplacementAlgorithm {
private:
    vector<int> frame;

    bool check(int referencePage);
    void fetch(int referencePage);
    
public:
    RANDAlgorithm(int frameSize);
    virtual ~RANDAlgorithm();
    
    void init();
};


#endif /* RANDAlgorithm_hpp */
