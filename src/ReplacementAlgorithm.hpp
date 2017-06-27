//
//  ReplacementAlgorithm.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 19..
//

#ifndef ReplacementAlgorithm_hpp
#define ReplacementAlgorithm_hpp

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// 페이지 교체 알고리즘 클래스
// 각각의 페이지 교체 알고리즘은 이 클래스를 상속받아 구현한다.
class ReplacementAlgorithm {
protected:
    int frameSize;      // 프레임 사이즈
    int countFault;     // 페이지 부재 횟수
    int countCall;      // 알고리즘 수행 횟수 (현재까지 탐색한 페이지수)
    string name;        // 알고리즘의 이름
    ofstream outFile;   // 출력 파일 스트림
    
    // 프레임 내에 참조하고자하는 페이지가 존재하는지 확인하는 함수
    virtual bool check(int referencePage) = 0;
    // 프레임 내의 한 페이지와 참조하고자하는 페이지를 교체하는 함수
    virtual void fetch(int referencePage) = 0;

public:
    // 생성자
    ReplacementAlgorithm(int frameSize) : frameSize(frameSize) {
        countFault = 0;
        countCall = 0;
    };
    // 소멸자
    virtual ~ReplacementAlgorithm() {
        outFile.close();    // 파일 스트림 닫기
    };
    
    // 초기화
    virtual void init() = 0;
    
    // 결과 출력 함수
    void printConsole() {
        int countHit = (countCall - countFault);
        printf("----------%s----------\n", name.c_str());

        printf("%20s%d\n", "Fault Count: ", countFault);
        printf("%20s%.2lf\n", "HIT ratio: ", (double)countHit/countCall);
        printf("%20s%.2lf\n", "FAULT ratio: ", (double)countFault/countCall);
        return;
    }
    
    // 각 참조열에 대해 프레임 내에 참고하고자하는 페이지가 존재하는지 확인하고(check)
    // 없다면 교체 작업을 실시한다. (fetch)
    void simulate(int referencePage) {
        // 프레임내에 referencePage가 존재하는가?
        if(!check(referencePage)) {
            countFault++;   // 페이지 부재 발생!
            // 프레임 내에 있는 페이지에 대해 교체 작업을 실시한다.
            fetch(referencePage);
        }
        countCall++;
        // 각 시점의 페이지 부재율을 파일로 출력
        outFile << (double)countFault/countCall << endl;
        return;
    }
};
#endif /* ReplacementAlgorithm_hpp */
