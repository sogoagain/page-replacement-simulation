//
//  ReferenceStringGenerator.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 18..
//

#include "ReferenceStringGenerator.hpp"

// name파일에서 참조열을 읽어오는 함수
vector<int> ReferenceStringGenerator::getReference(string name) {
    vector<int> referenceString;    // 참조열이 저장될 vector
    
    // 입력 파일 스트림에 파일을 읽어옴
    ifstream inputFile(name.data());
    
    // 입력 파일을 읽으면서 referenceString에 저장
    while(!inputFile.eof()){
        int memoryAddress;   // 메모리 주소
        inputFile >> memoryAddress;
        int page = memoryAddress;
        referenceString.push_back(page);
    }
    inputFile.close();  // 입력 파일 닫음
    
    // 참조열 반환
    return referenceString;
}

// 테스트를 위한 참조열 생성함수
vector<int> ReferenceStringGenerator::generateTestReference() {
    vector<int> referenceString;    // 참조열이 저장될 vector
    
    // 테스트를 위한 참조열 설정
    referenceString.push_back(7);
    referenceString.push_back(0);
    referenceString.push_back(1);
    referenceString.push_back(2);
    referenceString.push_back(0);
    referenceString.push_back(3);
    referenceString.push_back(0);
    referenceString.push_back(4);
    referenceString.push_back(2);
    referenceString.push_back(3);
    referenceString.push_back(0);
    referenceString.push_back(3);
    referenceString.push_back(2);
    referenceString.push_back(1);
    referenceString.push_back(2);
    referenceString.push_back(0);
    referenceString.push_back(1);
    referenceString.push_back(7);
    referenceString.push_back(0);
    referenceString.push_back(1);
    
    /* // SC 확인용
    referenceString.push_back(0);
    referenceString.push_back(4);
    referenceString.push_back(1);
    referenceString.push_back(4);
    referenceString.push_back(2);
    referenceString.push_back(4);
    referenceString.push_back(3);
    referenceString.push_back(4);
    referenceString.push_back(2);
    referenceString.push_back(4);
    referenceString.push_back(0);
    referenceString.push_back(4);
    referenceString.push_back(1);
    referenceString.push_back(4);
    referenceString.push_back(2);
    referenceString.push_back(4);
    referenceString.push_back(3);
    referenceString.push_back(4);
     */
    
    // 참조열 반환
    return referenceString;
}
