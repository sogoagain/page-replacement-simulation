//
//  MSCAlgorithm.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 6. 8..
//

#include "MSCAlgorithm.hpp"

// 생성자
MSCAlgorithm::MSCAlgorithm(int frameSize) : ReplacementAlgorithm(frameSize)  {
    srand((int)time(NULL));
    init();
    name = "MSC";
    outFile.open("MSC.txt", ios::trunc);
}

// 소멸자
MSCAlgorithm::~MSCAlgorithm() {
    vector<bool>().swap(referenceBits);
    vector<int>().swap(frame);
}

// PROBABILITY_OF_MUTATION 확률로 돌연변이를 발생시키는 함수
void MSCAlgorithm::occurMutation() {
    // 돌연변이가 발생하면 모든 참조비트의 값이 true로 설정된다.
    if(rand()%1000 < PROBABILITY_OF_MUTATION) {
        referenceBits.assign(frameSize, true);
    }
}

// 원형큐의 탐색 포인터를 증가시키는 함수
void MSCAlgorithm::increasePointer() {
    pointer = (pointer + 1)%frameSize;
}

// 프레임내에서 참조하고자하는 페이지가 있는지 검사하는 함수
bool MSCAlgorithm::check(int referencePage) {
    occurMutation();
    for(int i = 0; i < frameSize; i++) {
        // PAGE HIT!!!
        if(frame[i] == referencePage) {
            // Page Hit시 참조비트를 false로 설정한다.
            referenceBits[i] = true;
            return true;
        }
    }
    // PAGE FAULT!!!
    return false;
}

// 페이지를 교체하는 함수
void MSCAlgorithm::fetch(int referencePage) {
    bool isReplaced = false;    // 교체여부
    bool isAllHasChance = true; // 프레임내의 모든 페이지가 기회를 갖고 있는지 여부
    
    // 프레임 내의 모든 페이지가 2차 기회를 가지고 있는지 검사한다.
    for(int i = 0; i < frameSize; i++) {
        isAllHasChance = isAllHasChance && referenceBits[i];
    }
    
    // 교체가 수행될때까지 반복문 수행
    while(!isReplaced) {
        // 참조비트가 false거나 모든 페이지가 2차 기회를 가지고 있다면
        // 원형큐 프레임에서 포인터 위치의 페이지를 교체한다.
        if(!referenceBits[pointer] || isAllHasChance) {
            frame[pointer] = referencePage;
            isReplaced = true;
        } else {
            // 위의 경우가 아니라면 포인터 위치의 페이지 참조비트를 false로 설정
            referenceBits[pointer] = false;
        }
        // 원형큐 탐색 포인터 증가
        increasePointer();
    }
}

// 초기화
void MSCAlgorithm::init() {
    countCall = 0;
    countFault = 0;
    vector<bool>().swap(referenceBits);
    vector<int>().swap(frame);
    referenceBits.assign(frameSize, false);
    frame.assign(frameSize, -1);
    pointer = 0;
}
