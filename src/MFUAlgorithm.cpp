//
//  MFUAlgorithm.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 20..
//

#include "MFUAlgorithm.hpp"

// 생성자
MFUAlgorithm::MFUAlgorithm(int frameSize) : ReplacementAlgorithm(frameSize) {
    init();
    name = "MFU";
    outFile.open("MFU.txt", ios::trunc);
}

// 소멸자
MFUAlgorithm::~MFUAlgorithm() {
    vector<int>().swap(frame);
    vector<int>().swap(counter);
}

// 프레임내에서 참조하고자하는 페이지가 있는지 검사하는 함수
bool MFUAlgorithm::check(int referencePage) {
    // 프레임을 탐색하며 있는지 검사한다.
    for(int i = 0; i < frameSize; i++) {
        // PAGE HIT!!!
        if(frame[i] == referencePage) {
            // 프레임 내의 각 페이지에 대한 페이지 Hit횟수를 기록한다.
            counter[i]++;
            return true;
        }
    }
    // PAGE FAULT!!!
    return false;
}

// 페이지를 교체하는 함수
void MFUAlgorithm::fetch(int referencePage) {
    // 페이지 Hit횟수가 제일 큰 페이지를 찾고 그것을 교체한다.
    int index = (int) (max_element(counter.begin(), counter.end()) - counter.begin());
    frame[index] = referencePage;
    counter[index] = 0;
}

// 초기화
void MFUAlgorithm::init() {
    countCall = 0;
    countFault = 0;
    vector<int>().swap(counter);
    vector<int>().swap(frame);
    frame.assign(frameSize, -1);
    counter.assign(frameSize, std::numeric_limits<int>::max());
}
