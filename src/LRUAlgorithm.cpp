//
//  LRUAlgorithm.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 19..
//

#include "LRUAlgorithm.hpp"

// 생성자
LRUAlgorithm::LRUAlgorithm(int frameSize) : ReplacementAlgorithm(frameSize)  {
    init();
    name = "LRU";
    outFile.open("LRU.txt", ios::trunc);
}

// 소멸자
LRUAlgorithm::~LRUAlgorithm() { }

// 프레임내에서 참조하고자하는 페이지가 있는지 검사하는 함수
bool LRUAlgorithm::check(int referencePage) {
    // 프레임에 referencePage가 존재하는지 확인한다.
    list<int>::iterator findIterrator = std::find(frame.begin(), frame.end(), referencePage);
    
    // 반복자가 스택의 끝을 가리키면 PAGE FAULT!!!
    if(frame.end() == findIterrator){
        return false;
    }
    
    // 그렇지 않다면 PAGE HIT!!!
    // 해당 페이지 현재 위치에서 스택의 끝으로 옮긴다.
    frame.erase(findIterrator);
    frame.push_back(referencePage);
    return true;
}

// 페이지를 교체하는 함수
void LRUAlgorithm::fetch(int referencePage) {
    if(frame.size() == frameSize) {
        frame.pop_front();  // 스택의 아이템을 빼고
    }
    frame.push_back(referencePage); // 스택에 아이템을 넣는다.
}

// 알고리즘 초기화
void LRUAlgorithm::init() {
    countCall = 0;
    countFault = 0;
}
