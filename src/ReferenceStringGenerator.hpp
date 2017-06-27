//
//  ReferenceStringGenerator.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 18..
//

#ifndef ReferenceStringGenerator_hpp
#define ReferenceStringGenerator_hpp

#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 참조열을 생성하는 객체
class ReferenceStringGenerator {
public:
    static vector<int> getReference(string name);   // 파일로부터 참조열을 읽어오는 함수
    static vector<int> generateTestReference();     // 테스트를 위한 참조열을 생성하는 함수
};

#endif /* ReferenceStringGenerator_hpp */
