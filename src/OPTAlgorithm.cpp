//
//  OPTAlgorithm.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 20..
//

#include <algorithm>
#include "OPTAlgorithm.hpp"
using namespace std;

// 생성자
OPTAlgorithm::OPTAlgorithm(vector<int>& referenceString, int frameSize) : ReplacementAlgorithm(frameSize), referenceString(referenceString) {
    init();
    name = "OPT";
    outFile.open("OPT.txt", ios::trunc);
    
}

// 소멸자
OPTAlgorithm::~OPTAlgorithm() {
    vector<int>().swap(frame);
}

// 프레임내에서 참조하고자하는 페이지가 있는지 검사하는 함수
bool OPTAlgorithm::check(int referencePage) {
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
void OPTAlgorithm::fetch(int referencePage) {
    vector<int> prediction; // 현재 프레임에 있는 페이지들이 참조열에서 다시 등장할 인덱스(위치)를 저장함.
    // prediction 벡터 초기화
    prediction.assign(frameSize, std::numeric_limits<int>::max());
    
    // 프레임에 있는 페이지 각각에 대해서 다음에 나올 위치를 확인함.
    for(int i = 0; i < frameSize; i++) {
        for(int j = countCall; j < referenceString.size(); j++) {
            if(frame[i] == referenceString[j]) {
                prediction[i] = j;
                break;
            }
            // 만일 해당 frame[i]페이지가 참조열에서 다시 나오지 않는다면 int의 최대값으로 설정한다.
            prediction[i] = std::numeric_limits<int>::max();
        }
    }
    
    // prediction에서 제일 높은 값을 갖는(아예 나오지 않거나, 제일 늦게 나오는) 인덱스를 찾는다.
    // 프레임에서 해당 인덱스의 페이지를 교체한다.
    int index = (int) (max_element(prediction.begin(), prediction.end()) - prediction.begin());
    frame[index] = referencePage;
     
}

// 초기화
void OPTAlgorithm::init() {
    countCall = 0;
    countFault = 0;
    vector<int>().swap(frame);
    frame.assign(frameSize, -1);
}
