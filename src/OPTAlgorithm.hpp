//
//  OPTAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 20..
//

#ifndef OPTAlgorithm_hpp
#define OPTAlgorithm_hpp

#include <vector>
#include <list>
#include "ReplacementAlgorithm.hpp"
using namespace std;

class OPTAlgorithm : public ReplacementAlgorithm {
private:
    vector<int> referenceString;
    vector<int> frame;
    
    bool check(int referencePage);
    void fetch(int referencePage);
    
public:
    OPTAlgorithm(vector<int>& referenceString, int frameSize);
    virtual ~OPTAlgorithm();
    
    void init();
};

#endif /* OPTAlgorithm_hpp */
