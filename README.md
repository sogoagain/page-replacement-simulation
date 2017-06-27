# Page Replacement Simulation

c++로 작성된 페이지 교체 시뮬레이션입니다.

## 클래스 다이어그램

![UML_class](./img/UML_class.png)

### 사용패턴

1. Strategy Pattern
2. Template Method Pattern
3. Singleton Pattern

## 실험 결과

### 참조열의 구성

Locality에 따라 총 3가지 단계(level1~3)의 참조열 구성

level이 높을수록 참조열의 Locality가 높음

### Frame Size 500

![result_500](./img/result_500.png)

### Frame Size 1000

![result_1000](./img/result_1000.png)

### Frame Size 2000

![result_2000](./img/result_2000.png)

### Frame Size 4000

![result_4000](./img/result_4000.png)