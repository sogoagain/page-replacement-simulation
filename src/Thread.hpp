//
//  Thread.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 18..
//

#ifndef Thread_hpp
#define Thread_hpp

#include <pthread.h>
#include <stdio.h>

// Java의 Thread 클래스를 기반으로 모델링한 클래스
class Thread {
private:
    pthread_t threadID; // pthread_t 구조체 변수
    bool isRunning;     // Thread의 실행중 여부를 저장
    
public:
    // 생성자와 소멸자
    Thread();
    virtual ~Thread();
    
    int start();                // Thread 실행
    int join();                 // Thread join
    pthread_t self();           // threadID 반환
    virtual void* run() = 0;    // Thread를 통해 실행될 함수
};
#endif /* Thread_hpp */
