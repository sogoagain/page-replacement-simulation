//
//  ReplacementThread.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 19..
//

#ifndef ReplacementThread_hpp
#define ReplacementThread_hpp

#include <vector>

#include "Thread.hpp"
#include "ConsolePrinter.hpp"
#include "ReplacementAlgorithm.hpp"

using namespace std;

// 페이지 교체 알고리즘을 쓰레드로 수행하는 클래스
// Thread 클래스를 상속받는다.
class ReplacementThread : public Thread {
private:
    // 교체알고리즘 객체
    ReplacementAlgorithm* algorithm = nullptr;
    vector<int> referenceString;    // 참조열
    
public:
    // 생성자
    ReplacementThread(vector<int>& referenceString, ReplacementAlgorithm* algorithm) : referenceString(referenceString), algorithm(algorithm) {}
    // 소멸자
    virtual ~ReplacementThread() {delete algorithm;}
    
    // 쓰레드로 실행되는 함수
    virtual void* run() {
        algorithm->init();  // 알고리즘 객체 초기화
        
        // 페이지 참조열을 탐색하며 교체 알고리즘 수행
        for(int i = 0; i < referenceString.size(); i++) {
            algorithm->simulate(referenceString[i]);
        }       
        
        // 페이지 참조열 탐색이 완료되면 교체 알고리즘 수행 결과 출력
        ConsolePrinter& ConsolePrinter = ConsolePrinter::getInstance();
        ConsolePrinter.print(algorithm);
        
        return NULL;
    }
    
    // 해당 쓰레드에서 돌릴 교체 알고리즘 객체 설정
    void setAlgorithm(ReplacementAlgorithm* algorithm) {
        // 이미 설정된 교체 알고리즘이 존재하면 자원 반납 후 설정
        if(algorithm != NULL) {
            delete algorithm;
        }
        this->algorithm = algorithm;
    }
};


#endif /* ReplacementThread_hpp */
