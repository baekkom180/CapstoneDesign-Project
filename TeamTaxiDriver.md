#### **<u>화분 키우기 어렵지 않아요</u>**



- 팀명: 꽃을 심는 남자들
- 브랜드명: 아직 미정 



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

폭력 사건 = (탑승객이 운전석의 영역으로 침범하는 횟수) + (침범하고 있는 시간) + (욕설 or 일정한 수준 이상의 소리 크기)
를 통해서 폭력 사건이 일어나고 있음을 판단합니다.

만약 폭력 사건이 일어나고 있다고 판단되면 자동으로 보호격막이 내려오도록 조치합니다.



## 예상 시스템 구성도

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/프로젝트 흐름도.PNG" width="60%" height="50%">

###### 




## 기대성과
사용자들이 보다 직관적으로 볼 수 있어서 더욱 더 편하게 확인할 수 있고 작동법이 따로 존재하지 않아서 편리하게 확인할 수 있습니다.

## 팀원
임준묵

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/%EC%9E%84%EC%A4%80%EB%AC%B5.jpg" width="15%" height="15%">

최진규

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/%EC%B5%9C%EC%A7%84%EA%B7%9C.jpg" width="15%" height="15%">

장성욱

<img src="https://github.com/baekkom180/CapstoneDesign-Project/blob/master/images/%EC%9E%A5%EC%84%B1%EC%9A%B1.jpg" width="15%" height="15%">

## 역할 분담
임준묵 -- DB 구축

최진규 -- 서버 구축

장성욱 -- 센서담당 및 기획

## 개발 환경
개발 도구 :: GitHub, Slack, mysql
