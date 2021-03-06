#### **<u>안전한 택시문화를 </u>**



- 팀명: TeamTaxiDriver
- 브랜드명: 나만 믿으라구



## Pain Point

택시기사들은 늘 차에 탑승한 탑승객으로부터 폭행의 위협을 받습니다.
밤 늦은 시간대, 만취한 승객이 택시기사를 폭행했다는 뉴스는 심심찮게 이슈화되곤 합니다.

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/캡처6.PNG" width="60%" height="50%">

차량 내에서 조수석, 혹은 뒷좌석에 앉은 승객이 택시기사를 폭행한다면
운전하고 있는 택시기사는 폭행에 반응하기 힘듭니다.

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/캡처1.PNG" width="60%" height="50%">
<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/캡처2.PNG" width="60%" height="50%">
<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/캡처3.PNG" width="60%" height="50%">
<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/캡처4.PNG" width="60%" height="50%">
<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/캡처5.PNG" width="60%" height="50%">

이러한 종류의 폭행은 단순히 택시기사의 생명을 위협할 뿐만 아니라
도로위의 다른 운전자, 보행자, 심지어 폭행 가해자까지도 위험한 안전 사고로 이어질 수 있습니다.

택시에 보호격막 설치는 이전부터 주장되고 있고
정부 또는 택시운송회사에서 지원도 해주고 있지만 
제대로 설치되고 있지 못합니다.
보호격막이 설치되면 운전자도, 승객도 답답하기 때문입니다.

IoT 기술을 이용하여, 이러한 문제점을 가진 기존 보호격막을
정말로 폭력 사건이 일어나는 경우에만 자동으로 
설치되도록 할 예정입니다.



## 어떻게?

폭력 사건이 일어나고 있는 지를 센서로 감지하는 건 그리 쉬운일은 아닙니다.
따라서 저희는 여러 다른 종류의 센서를 통해서 데이터를 수집합니다.

1. 거리센서: 운전석과 조수석 사이, 운전석과 뒷좌석 사이에 거리센서를 통해서 누군가
   운전석의 영역으로 들어왔는지를 측정합니다. 또한 얼마나 넘어왔는지도 측정합니다.
   
2. 소리센서: 소리 센서로 폭력이 일어날 경우의 주변 소리를 수집합니다. 
   폭력 사건의 경우, 큰 소리나 비명소리 욕설 같은 소리 단서가 있다는 가정하에 데이터를 수집합니다.
   
폭력 사건 = (탑승객이 운전석의 영역으로 침범하는 횟수) + (침범하고 있는 시간) + (일정한 수준 이상의 소리 크기)
를 통해서 폭력 사건이 일어나고 있음을 판단합니다.

만약 폭력 사건이 일어나고 있다고 판단되면 자동으로 보호격막이 내려오도록 조치합니다.



## 예상 시스템 구성도

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/%ED%9D%90%EB%A6%84%EB%8F%84%20%EC%B5%9C%EC%A2%85.JPG" width="100%" height="100%">

## DB 스키마

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/DB%20%EC%8A%A4%ED%82%A4%EB%A7%88.JPG" width="100%" height= "100%">

###### 

## 기술 구현 단계

1. 센서로 데이터 수집  
1-1. 거리센서를 이용하여 인체가 운전석으로 넘어오는 횟수와 시간 수집  
1-2. 소리센서를 이용하여 소리의 크기 감지  

2. DB 구축  
2-1. 거리센서를 통한 거리 데이터(1초 주기) 저장  
2-1. 소리센서를 통한 소리 데이터(1초 주기) 저장 

3. 서버 구축  
3-1. 거리 센서에서 오는 데이터를 서버로 전송  
3-2. 소리 센서에서 오는 데이터를 서버로 전송    

4. 모터 작동  
4-0. (예비 과정) 모터 대신 led 작동(완료)  
4-1. 모터 작동(완료)   

5. 수집한 데이터를 통해서 폭력사건 판단 공식(완료)  

## 데이터 수집
1. 거리 센서로 인체 데이터 수집(완료)  
2. 소리 센서로 폭력 사건의 소음 수준 측정(완료)  

## 폭력사건 판단 공식  
-폭력사건 => (인체가 운전석을 침범하는 횟수, 시간) + (폭력사건의 소음의 정도) 
데이터를 종합해서 팀원끼리 폭력사건을 재연하고 이 3가지 항목의 수치를 계산하여 공식 완성.   

## 시연 영상
- 간이 영상 https://www.youtube.com/watch?v=ES3JsgDgxBE&feature=youtu.be 
- 격벽 움직이는 영상 https://www.youtube.com/watch?v=Y4wGCtL2KTo
- 승객이 카드 결제만 하는 과정 https://www.youtube.com/watch?v=Hsjz-vv6uJo  //  https://www.youtube.com/watch?v=ihXlEs6MZz0
- 뒷자석 승객이 온몸이 넘어와서 폭행하는 경우  https://www.youtube.com/watch?v=BVFLSDI5WQM
- 뒷자석 승객이 주먹만 넘어와서 폭행하는 경우  https://www.youtube.com/watch?v=DjcNbYQNrrE
- 조수석 승객이 온몸이 넘어와서 폭행하는 경우  https://www.youtube.com/watch?v=yJg_aW0CnPo
- 조수석 승객이 주먹만 넘어와서 폭행하는 경우  https://www.youtube.com/watch?v=ZhNpAVKCXI8


## 기대성과
일단 두 가지의 성과를 기대할 수 있을것이라 생각합니다.  

1. 폭력으로부터 보호받지 못하는 택시기사분들을 보호할 수 있습니다.  
2. 폭력으로 인해서 택시기사가 위협받는 경우에 택시기사 뿐만 아니라  
   보행자, 가해자까지 위협받을 수 있는데 우리의 제품은 이러한 상황으로 부터  
   보행자분들을 보호할 수 있을것이라 생각합니다.  
추가적으로 발생하는 성과는 저희가 직접 실험을 해보고 체험을 해보면서 추가해 나갈 예정입니다.  

## 팀원
임준묵

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/%EC%9E%84%EC%A4%80%EB%AC%B5.jpg" width="15%" height="15%">

최진규

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/%EC%B5%9C%EC%A7%84%EA%B7%9C.jpg" width="15%" height="15%">

장성욱

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/%EC%9E%A5%EC%84%B1%EC%9A%B1.jpg" width="15%" height="15%">

## 역할 분담
임준묵 -- 센서 부착 및 작동 확인

최진규 -- 구동 알고리즘 작성

장성욱 -- 서버 구축 및 관리

## 개발 환경
개발 도구 :: GitHub, Slack, mysql
