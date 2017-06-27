//
//  LRUAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 19..
//

#ifndef LRUAlgorithm_hpp
#define LRUAlgorithm_hpp

#include <algorithm>
#include <list>
#include "ReplacementAlgorithm.hpp"
using namespace std;

class LRUAlgorithm : public ReplacementAlgorithm {
private:
    list<int> frame;
    
    bool check(int referencePage);
    void fetch(int referencePage);
    
public:
    LRUAlgorithm(int frameSize);
    virtual ~LRUAlgorithm();
    
    void init();
};

#endif /* LRUAlgorithm_hpp */
