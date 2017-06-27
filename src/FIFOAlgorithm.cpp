//
//  FIFOAlgorithm.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 19..
//

#include "FIFOAlgorithm.hpp"

// 생성자
FIFOAlgorithm::FIFOAlgorithm(int frameSize) : ReplacementAlgorithm(frameSize) {
    init();         // 초기화
    name = "FIFO";  // 알고리즘 이름 설정
    outFile.open("FIFO.txt", ios::trunc);   // 출력 파일 스트림 open
}

// 소멸자
FIFOAlgorithm::~FIFOAlgorithm() { }

// 프레임내에서 참조하고자하는 페이지가 있는지 검사하는 함수
bool FIFOAlgorithm::check(int referencePage) {
    // 프레임에 referencePage가 존재하는지 확인한다.
    list<int>::iterator findIterrator = std::find(frame.begin(), frame.end(), referencePage);
    
    // 반복자가 큐의 끝을 가리키면 PAGE FAULT!!!
    if(frame.end() == findIterrator){
        return false;
    }
    // 그렇지 않다면 PAGE HIT!!!
    return true;
}

// 페이지를 교체하는 함수
void FIFOAlgorithm::fetch(int referencePage) {
    // 프레임이 꽉찼다면,
    if(frame.size() == frameSize) {
        frame.pop_front();  // 큐의 처음 아이템을 빼고
    }
    frame.push_back(referencePage); // 큐 제일 뒤에 아이템을 넣는다.
}

// 알고리즘 초기화 함수
void FIFOAlgorithm::init() {
    countCall = 0;
    countFault = 0;
}
