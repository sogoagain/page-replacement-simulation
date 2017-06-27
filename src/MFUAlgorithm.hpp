//
//  MFUAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 20..
//

#ifndef MFUAlgorithm_hpp
#define MFUAlgorithm_hpp

#include <algorithm>
#include <vector>
#include <map>
#include "ReplacementAlgorithm.hpp"
using namespace std;

class MFUAlgorithm : public ReplacementAlgorithm {
private:
    vector<int> frame;
    vector<int> counter;
    
    bool check(int referencePage);
    void fetch(int referencePage);
    
public:
    MFUAlgorithm(int frameSize);
    virtual ~MFUAlgorithm();
    
    void init();
};


#endif /* MFUAlgorithm_hpp */
