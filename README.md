# RpgSimulator
스마일게이트 직무체험 인턴에서 진행한 프로젝트로 개인 프로젝트인 FindArk의 문제점을 개선하고 

### 프로젝트 개요
1. 프로젝트 기간: 2023. 07. 03 ~ 2023. 08. 25
<br/>

2. 개발 도구 및 개발 환경: </br>
    <img src="https://img.shields.io/badge/UnrealEngine-0E1128?style=for-the-badge&logo=UnrealEngine&logoColor=white"> <img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=Windows&logoColor=white">
<br/>

3. 참여 인원: 1인

4. 프로젝트 개요
    * Unreal Engine 5(5.0.3), C++(80%) & Blueprint(20%) 구현
    * RPG 게임의 보스 레이드 콘텐츠 구현
    * 플레이어 캐릭터(4개), 보스 몬스터(1개), 공격 스킬(각 8개), 몬스터의 BT 인공지능 구현 (Blueprint)
    * 위젯 구현
    * Deep Learning 학습에 필요한 feature 선정 및 구조화
    * Deep Learning 학습에 필요한 기능(Headless, 가속화, Config 파싱 등) 구현
    <br/>
    <img src="./assets/Architecture.png">
<br/>

### 프로젝트 세부 내용
**1. 캐릭터 구현**
* 캐릭터는 직접 조작, BT를 사용한 조작, Deep Learning 결과에 따른 조작으로 제어할 수 있으며, JSON 파일로 설정
* 각 캐릭터에는 UDP 소켓이 구현되어 있으며, Deep Learning을 사용할 경우 UDP 패킷 메시지에 따라 데이터 송수신, 시뮬레이션 리셋, 시뮬레이션 종료를 처리
* BaseCharacter 클래스(C++)에서 공통 기능을 구현한 후 Blueprint로 상속하여 스킬, 데미지 처리 등을 구현
* 공격 스킬은 모션에 맞춰 발동되도록 Anim Montage에 AnimNotify를 추가하고 Notify에서 캐릭터의 데미지 전달 함수를 호출하도록 구현

<br/>

**2. 보스 몬스터 및 BT 기반 AI 구현**
* BT를 사용하여 전투 시나리오가 가능한 AI 기능
<br/>

**3. 보스 몬스터 및 BT 기반 AI 구현**
* BT를 사용하여 전투 시나리오가 가능한 AI 기능 구현 (Blueprint)
* 보스의 기본 스킬 4개와 기믹에 사용되는 특수 스킬 3개 구현
<img src=./assets/Scenario.png>

<br/>

**3. 게임 시스템 구현**
* Game Instance 구현 (Blueprint)
    * 게임을 실행할 때, 캐릭터, 보스 몬스터, 게임 규칙 등 필요한 정보를 JSON 파일에서 파싱
    * 파싱된 데이터는 구조체로 관리

* Game Mode 구현 (Blueprint)
    * 게임이 시작될 때, 캐릭터, 보스 몬스터, 게임 규칙을 Game Instance에서 파싱한 JSON 데이터를 사용해 초기화
    * 게임의 제한 시간, 리셋, 종료 등을 관리

<br/>

**4. 시뮬레이션 기능 구현**
* Deep Learning 학습에서 매 시뮬레이션마다 파라미터를 수정할 수 있도록 JSON & CSV 데이터 파싱 구현 (Blueprint)
* Deep Learning 학습에는 렌더링이 필요없으므로 Headless 기능 구현
* 시뮬레이션에 소요되는 물리적 시간을 단축하기 위해 가속화 기능 구현
<br/>

### 시연 영상
[레이드 시나리오 기믹 video (Youtube)](https://youtu.be/ECHzW10TmL4)