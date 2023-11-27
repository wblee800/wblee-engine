#pragma once
#include <Windows.h>

#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "WBMath.h"
#include "WBEnum.h"

// Msimg32.lib : 
// GDI�� ���õ� �̹��� ó���� ���õ� �� ���� Ȯ�� ����� ����
#pragma comment(lib, "Msimg32.lib")

// winmm.lib :
// ����� �� ������ ���� ��Ƽ�̵�� ����� ����ϱ� ���� 
// �Լ��� ���ҽ��� ����
#pragma comment(lib, "winmm.lib")

#include <objidl.h>
#include <gdiplus.h>
// gdiplus.lib :
// �׷����� �ٷ�� ���� ��� �׷��� ���̺귯��, GDI�� Ȯ��� ����
// �̹��� ó��, �׸��� �� �ؽ�Ʈ �������� ���� �۾��� �����ϴ� �� ���
#pragma comment(lib, "gdiplus.lib")