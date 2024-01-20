
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Alt text](resources/readme_image/StardewValleyLogo.png)

<br>

## 🧐 프로젝트 소개

>🚜 스타듀밸리는 기존 게임을 게이머가 원하는 대로 수정할 수 있는 MOD가 있다는 점에서 착안해 기존 스토리를 각색하여 개발했습니다.
>
>🪟 Win32 API를 이용해 개발했고, 게임 엔진은 Unity를 모티브로 하여 클래스, 함수 등을 Unity와 유사하게 구성했습니다.

<br>

## 📜 각색한 스토리
>여러분은 🚜 스타듀밸리에 있는 할아버지의 오래된 농장을 .물려받게 됩니다. 하지만, 농장에는 비밀이 묻혀있습니다. 바로.. 조자 코퍼레이션의 💸 채권이죠..! 자급자족하면서 웃자란 농경지를 잘 나가는 내 농장으로 탈바꿈 시킬 수 있을까요? 쉽지는 않을 겁니다. 하지만 조자 코퍼레이션의 채권을 찾는다면 이야기는 달라질 겁니다. 
>
>따라서 여러분은 채권을 찾아 조자 코퍼레이션에게 요구해 낡은 마을을 수리하고 농장을 운영하는 데 필요한 것들을 모두 챙기세요! 여러분이 조금만 노력한다면 스타듀 밸리에 과거의 영광을 되찾아주는 영웅이 될 수도 있습니다!

<br>

## 🎮 콘텐츠 소개
- ### 씬
  ![Alt text](resources/readme_image/Scenes.png)
  <b>위 씬들을 모두 구현했습니다.<br>
  하지만, 개발 일정 문제로 농장, 집, 하수구 입구, 하수구, 조자마트 씬만을 사용했습니다.</b>

- ### 캐릭터
  - <b>플레이어
    - 특정 키 입력에 따라 이동 및 장비 사용
    - 몬스터와 접촉 시 데미지를 입고, 특정 횟수 이상이면, 기절
  - 고양이
    - FSM을 이용한 AI 구현 ∴ 키 입력 없이도 고양이가 알아서 움직입니다.
  - 하수구 괴물
    - 플레이어를 발견하면, 알아서 따라가는 AI 구현
    - 플레이어와 접촉 시, 플레이어에게 데미지를 입힙니다.
    - 플레이어가 검을 휘두렀을 때 맞으면, 데미지를 입습니다.</b>
    
- ### 사운드


<br>

## 💻 엔진 구조 살펴보기
![Alt text](resources/readme_image/ClassDiagram.png)