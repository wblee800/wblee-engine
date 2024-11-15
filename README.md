
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Alt text](/resources/readme_img/StardewValleyLogo.png)

<br>

## 🧐 Project Introduction 프로젝트 소개

>🚜 Inspired by the concept of MODs that allow gamers to modify existing games as they like, this project was developed by adapting an existing story.
> 기존 게임을 게이머가 원하는 대로 수정할 수 있는 MOD가 있다는 점에서 착안해 기존 스토리를 각색하여 개발했습니다.
>
>🪟 Using Windows API, the game engine and content were developed. The engine was modeled after Unity, with classes and functions structured similarly to Unity.
> Windows API를 이용해 게임 엔진과 콘텐츠를 개발했고, 게임 엔진은 Unity를 모티브로 하여 클래스, 함수 등을 Unity와 유사하게 구성했습니다.

<br>

## 📜 Adapted Story 각색한 스토리
> You inherit your grandfather's old farm in 🚜 Stardew Valley. However, there’s a hidden secret on the farm: Joja Corporation’s 💸 bonds! Can you transform this overgrown farmland into a thriving enterprise? It won't be easy, but if you uncover Joja Corporation's bonds, the story might take a dramatic turn.
> Your mission is to find the bonds and demand your rights from Joja Corporation! Restore the old town, gather everything you need to manage the farm, and bring Stardew Valley back to its former glory 🤑. With a bit of effort, you could become the hero Stardew Valley has been waiting for!

> 여러분은 🚜 스타듀밸리에 있는 할아버지의 오래된 농장을 물려받게 됩니다. 하지만, 농장에는 비밀이 묻혀있습니다. 바로.. 조자 코퍼레이션의 💸 채권이죠..! 자급자족하면서 웃자란 농경지를 잘 나가는 내 농장으로 탈바꿈 시킬 수 있을까요? 쉽지는 않을 겁니다. 하지만 조자 코퍼레이션의 채권을 찾는다면 이야기는 달라질 겁니다. 
>
>따라서 여러분은 채권을 찾아 조자 코퍼레이션에게 요구하세요! 그리고 낡은 마을을 수리하고 농장을 운영하는 데 필요한 것들을 모두 챙기세요🤑 여러분이 조금만 노력한다면 스타듀 밸리에 과거의 영광을 되찾아주는 영웅이 될 수도 있습니다!

<br>

## 🎮 Content Overview 콘텐츠 소개
- ### Scenes
  ![Alt text](/resources/readme_img/Scenes.png)
  <b>All of the scenes above were implemented. 위 씬들을 모두 구현했습니다.<br>
  However, due to development schedule constraints, only the farm, house, sewer entrance, sewer, and JojaMart scenes were used.
  하지만, 개발 일정 문제로 농장, 집, 하수구 입구, 하수구, 조자마트 씬만을 사용했습니다.</b>

- ### Characters and Character Scripts 캐릭터 및 캐릭터 스크립트
  - <b>Player 플레이어
    - Implemented movement and directional animations based on specific key inputs. 특정 키 입력하면 이동 및 방향에 따른 애니메이션 구현
    - Implemented equipment usage animations according to equipment type and direction based on key inputs. 특정 키 입력에 따라 장비 사용 및 장비 종류와 방향에 따른 애니메이션 구현
  - Cat 고양이
    - AI implemented using FSM (Finite State Machine), allowing the cat to move autonomously without player input. FSM을 이용한 AI 구현 ∴ 키 입력 없이도 고양이가 알아서 움직입니다.
    
- ### Sound 사운드
  - Sound effects implemented for each scene. 씬에 따른 사운드 구현
</b>
<br>

## 💻 Engine Structure Overview 엔진 구조 살펴보기
![Alt text](/resources/readme_img/ClassDiagram.png)
