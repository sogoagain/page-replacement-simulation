//
//  RANDAlgorithm.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 20..
//

#include "RANDAlgorithm.hpp"


// 생성자
RANDAlgorithm::RANDAlgorithm(int frameSize) : ReplacementAlgorithm(frameSize) {
    srand((int)time(NULL));
    init();
    name = "RAND";
    outFile.open("RAND.txt", ios::trunc);
}

// 소멸자
RANDAlgorithm::~RANDAlgorithm() {
    vector<int>().swap(frame);
}

// 프레임내에서 참조하고자하는 페이지가 있는지 검사하는 함수
bool RANDAlgorithm::check(int referencePage) {
    // 프레임을 탐색하며 있는지 검사한다.
    for(int i = 0; i < frameSize; i++) {
        // PAGE HIT!!!
        if(frame[i] == referencePage) {
            return true;
        }
    }
    // PAGE FAULT!!!
    return false;
}

// 페이지를 교체하는 함수
void RANDAlgorithm::fetch(int referencePage) {
    // 프레임 내의 랜덤한 위치의 페이지를 교체한다.
    int index = 0;
    // 프레임에 빈 곳이 있다면 순서대로 저장
    if(countCall < frameSize) {
        index = countCall;
    } else {
        index = rand()%frameSize;
    }
    frame[index] = referencePage;
}

// 초기화
void RANDAlgorithm::init() {
    vector<int>().swap(frame);
    frame.assign(frameSize, -1);
}
