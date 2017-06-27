//
//  ConsolePrinter.hpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 19..
//

#ifndef ConsolePrinter_hpp
#define ConsolePrinter_hpp

#include <mutex>
#include "ReplacementAlgorithm.hpp"
using namespace std;

// ConselePrinter 클래스는 멀티 쓰레드 환경에서 콘솔 출력을 동기화하기 위한 클래스다.
// 싱글턴 패턴을 이용해 설계되었다.
/*
*      ConsolePrinter 클래스는 결과 출력시 사용되는 클래스입니다.
*          멀티 쓰레드를 통해 여러 알고리즘을 동시에 실행하다보니, 결과 출력시 race condition이 발생해
*          결과 출력이 뒤죽박죽됩니다.
*          따라서 ConsolePrinter 클래스 내부에서 mutex 동기화를 통해 각 알고리즘의 printConsole() 함수를 호출합니다.
*          mutex 변수는 하나로 공유해야합니다.
*          따라서 ConsolePrinter 클래스는 객체지향 디자인 패턴 중 '싱글턴 패턴'을 이용해 설계했습니다.
*/
class ConsolePrinter {
private:
    mutex mutexLock;    // mutex잠금을 사용하기 위한 mutex 변수
    ConsolePrinter(){}  // 생성자, 싱글턴이므로 private이다.
public:
    // 싱글턴 패턴을 이용하였으므로 외부에서 getInstance()를 이용해 객체를 반환받음
    static ConsolePrinter& getInstance() {
        static ConsolePrinter instance; // 오직 1개의 객체를 만들기위해 static 변수 이용
        return instance;
    }
    // 복사 생성자 및 대입 연산자에대한 싱글턴 패턴 처리
    ConsolePrinter(const ConsolePrinter &) = delete;
    void operator=(const ConsolePrinter &) = delete;
    virtual ~ConsolePrinter(){} // 소멸자
    
    // 콘솔에 매개변수로 들어온 알고리즘의 결과를 출력하는 함수
    // 뮤텍스 잠금을 이용한다.
    void print(ReplacementAlgorithm* algorithm) {
        mutexLock.lock();   // 뮤텍스 잠금
        algorithm->printConsole();  // 결과출력
        mutexLock.unlock(); // 뮤텍스 잠금 해제
    }
};

#endif /* Printer_hpp */
