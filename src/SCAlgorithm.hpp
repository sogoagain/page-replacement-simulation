//
//  SCAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 26..
//
// http://www.mathcs.emory.edu/~cheung/Courses/355/Syllabus/9-virtual-mem/SC-replace.html

#ifndef SCAlgorithm_hpp
#define SCAlgorithm_hpp

#include <algorithm>
#include <vector>
#include "ReplacementAlgorithm.hpp"
using namespace std;

class SCAlgorithm : public ReplacementAlgorithm {
private:
    vector<int> frame;
    vector<bool> referenceBits;
    int pointer = 0;
    
    void increasePointer();
    bool check(int referencePage);
    void fetch(int referencePage);
    
public:
    SCAlgorithm(int frameSize);
    virtual ~SCAlgorithm();
    
    void init();
};


#endif /* SCAlgorithm_hpp */
