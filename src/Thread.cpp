//
//  Thread.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 18..
//

#include "Thread.hpp"

// 생성자
Thread::Thread() : threadID(0), isRunning(false) { }

// 소멸자
Thread::~Thread() {
    if(isRunning == true) {
        pthread_cancel(threadID);
    }
}

// Thread 객체의 run() 메소드를 호출
static void* runThread(void* arg) {
    return static_cast<Thread*>(arg)->run();
}

// Thread 실행
int Thread::start() {
    int result = pthread_create(&threadID, NULL, runThread, this);
    // 쓰레드 생성에 대한 예외처리
    if(result != 0) {
        perror("pthread_create failed");
    }
    
    // 쓰레드가 생성되었으므로 실행여부를 나타내는 isRunning 변수를 true로 설정한다.
    isRunning = true;
    return result;
}

// Thread join
int Thread::join() {
    int result = -1;
    // 쓰레드 조인
    if(isRunning) {
        result = pthread_join(threadID, NULL);
    }
    // 쓰레드 조인에 대한 예외처리
    if(result != 0) {
        perror("pthread_join failed\n");
    }
    
    // 쓰레드가 조인되었으므로 isRunning을 false로 설정.
    isRunning = false;
    return result;
}

// threadID 반환
pthread_t Thread::self() {
    return threadID;
}
