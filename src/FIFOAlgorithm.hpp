//
//  FIFOAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 19..
//

#ifndef FIFOAlgorithm_hpp
#define FIFOAlgorithm_hpp

#include <algorithm>
#include <list>
#include "ReplacementAlgorithm.hpp"
using namespace std;

class FIFOAlgorithm : public ReplacementAlgorithm {
private:
    list<int> frame;
 
    bool check(int referencePage);
    void fetch(int referencePage);
    
public:
    FIFOAlgorithm(int frameSize);
    virtual ~FIFOAlgorithm();
    
    void init();
};

#endif /* FIFOAlgorithm_hpp */
