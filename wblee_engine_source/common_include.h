#pragma once
#include <Windows.h>

#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "WBMath.h"
#include "WBEnum.h"

// Msimg32.lib : 
// GDI와 관련된 이미지 처리와 관련된 몇 가지 확장 기능을 제공
#pragma comment(lib, "Msimg32.lib")

// winmm.lib :
// 오디오 및 비디오와 같은 멀티미디어 기능을 사용하기 위한 
// 함수와 리소스를 제공
#pragma comment(lib, "winmm.lib")

#include <objidl.h>
#include <gdiplus.h>
// gdiplus.lib :
// 그래픽을 다루기 위한 고급 그래픽 라이브러리, GDI의 확장된 버전
// 이미지 처리, 그리기 및 텍스트 렌더링과 같은 작업을 수행하는 데 사용
#pragma comment(lib, "gdiplus.lib")