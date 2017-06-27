//
//  main.cpp
//  PageReplacementSimulation
//
//  Created by Thinkronize on 2017. 5. 18..
//

/*
 *  - 전체적인 클래스 설계
 *      (1) 객체지향 디자인 패턴 중 하나인 '전략패턴'과 '템플릿 메소드 패턴'을 이용해 설계했습니다.
 *      (2) Thread 클래스는 Java의 Thread 클래스 이용법을 기반으로 c++ 형태로 작성한 것입니다.
 *      (3) ReplacementThread 클래스는 Thread 클래스를 상속받는 클래스로,
 *          페이지 교체 알고리즘을 쓰레드로 수행할 수 있는 클래스입니다.
 *      (4) ReplacementThread 클래스는 ReplacementAlgorithm 추상클래스를
 *          has-a 관계로 가지고 있습니다.
 *      (5) ReplacementAlgorithm 클래스가 바로 페이지 교체 알고리즘을 수행하는 전략(행위)입니다.
 *      (6) 각각의 페이지 교체 알고리즘은 ReplacementAlgorithm 클래스를 상속받아 구현합니다.
 *      (7) 위와 같이 설계함으로써 ReplacementThread 클래스 내부의 참조변수만 바꿈으로써
 *          수행되는 알고리즘을 동적으로 손쉽게 변경할 수 있습니다.
 *          또한 행위의 구현을 구분해 손쉽게 작업할 수 있습니다.
 *      (8) ConsolePrinter 클래스는 결과 출력시 사용되는 클래스입니다.
 *          멀티 쓰레드를 통해 여러 알고리즘을 동시에 실행하다보니, 결과 출력시 race condition이 발생해
 *          결과 출력이 뒤죽박죽됩니다.
 *          따라서 ConsolePrinter 클래스 내부에서 mutex 동기화를 통해 각 알고리즘의 printConsole() 함수를 호출합니다.
 *          mutex 변수는 하나로 공유해야합니다.
 *          따라서 ConsolePrinter 클래스는 객체지향 디자인 패턴 중 '싱글턴 패턴'을 이용해 설계했습니다.
 *
 *  - 각 페이지 교체 알고리즘은 ReplacementAlgorithm 추상클래스를 상속받아 구현합니다.
 *    페이지 교체 알고리즘은 다음 두가지 행위를 하게됩니다.
 *    ReplacementAlgorithm 클래스에 다음 두함수를 virtual 함수로 정의하였습니다.
 *     (1) 프레임 내에 참고하고자 하는 페이지가 있는지 검사하는 모듈 - check 함수
 *     (2) 프레임에 있는 페이지를 교체하는 모듈                 - fetch 함수
 *    simulate() 함수는 ReplacementThread 클래스 내에서 참조열을 확인할때마다 호출됩니다.
 *    sumulate() 함수 내부에서 check()와 fetch()가 불리게됩니다.
 *    printConsole() 함수는 콘솔에 전체 결과를 출력합니다.
 *
 *  - 개발 규칙
 *      (1) 단순 배열을 사용하기 보다는 vector, list, queue, stack과 같은 컨테이너 자료구조를 이용하였습니다.
 *
 *  - 파일 규칙
 *      (1) 클래스를 정의할때는 클래스명과 같은 이름으로 .hpp파일과 .cpp파일을 생성합니다.
 *      (2) .hpp 파일에 클래스의 전체적인 모습을 정의하고 .cpp파일에서 세부사항을 구현합니다.
 */

#include <iostream>
#include "ReplacementThread.hpp"
#include "ReferenceStringGenerator.hpp"

// 페이지 교체 알고리즘 헤더파일 선언부
#include "FIFOAlgorithm.hpp"
#include "OPTAlgorithm.hpp"
#include "LRUAlgorithm.hpp"
#include "MFUAlgorithm.hpp"
#include "RANDAlgorithm.hpp"
#include "SCAlgorithm.hpp"
#include "MSCAlgorithm.hpp"

#define NUMBER_OF_ALGORITHM 7      // 테스트할 알고리즘의 갯수

int main(int argc, const char * argv[]) {
    int frameSize;
    string referenceFile;
    
    if(argc != 3) {
        printf("Usage: %s [frame size] [reference file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    frameSize = atoi(argv[1]);
    referenceFile = argv[2];
    
    printf("-----Start Simulation-----\n");
    /*******************참조열 생성*******************/
    vector<int> referenceString = ReferenceStringGenerator::getReference(referenceFile.data());
    // vector<int> referenceString = ReferenceStringGenerator::generateTestReference();
    
    // 참조열 출력
    /*
    for(int page : referenceString) {
        printf("%d ", page);
    }
    printf("\n");
    */
    /**********************************************/
    
    /**********페이지 교체 알고리즘 시뮬레이션**************/
    // Page Replacement Algorithm들을 Multi Thread를 통해 실행
    Thread* thread[NUMBER_OF_ALGORITHM];

    // 페이지 교체 알고리즘 쓰레드 생성
    thread[0] = new ReplacementThread(referenceString, new FIFOAlgorithm(frameSize));
    thread[1] = new ReplacementThread(referenceString, new OPTAlgorithm(referenceString, frameSize));
    thread[2] = new ReplacementThread(referenceString, new LRUAlgorithm(frameSize));
    thread[3] = new ReplacementThread(referenceString, new MFUAlgorithm(frameSize));
    thread[4] = new ReplacementThread(referenceString, new RANDAlgorithm(frameSize));
    thread[5] = new ReplacementThread(referenceString, new SCAlgorithm(frameSize));
    thread[6] = new ReplacementThread(referenceString, new MSCAlgorithm(frameSize));

    // 각 쓰레드 실행
    for(Thread* algorithm : thread) {
        algorithm->start();
    }
    printf("\tProgress...\n");

    // 쓰레드 join
    for(Thread* algorithm : thread) {
        algorithm->join();
        delete algorithm;   // 쓰레드 객체 자원 반납
    }
    printf("-----Finish Simulation-----\n");
    /**********************************************/
    
    /********************자원 반납********************/
    vector<int>().swap(referenceString);
    /**********************************************/
        
    return 0;
}
