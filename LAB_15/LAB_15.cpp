﻿// LAB_15.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "LAB_15.h"
#include "Images.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int image1_x = 100;
int image1_y = 100;


// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB15, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB15));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB15));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB15);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
struct Image {
    int x;
    int y;
    int vx;
    int vy;
};

struct Image im1 = { 100, 200, 10, 0 };
typedef struct Image IMAGE;
IMAGE im2 = { 400, 200, -10, 0 };
IMAGE im3 = { 400, 200, 0, 10 };
IMAGE im4 = { 100, 200, 0, -10 };
int dx5;
int dy5;
IMAGE im5 = { 100, 200, dx5, dy5 };

#define NUM_IM_A 9
IMAGE imA[NUM_IM_A] = {
    {700, 300, 10, 0},
    {700, 300, 9, 4},
    {700, 300, 7, 7},
    {700, 300, 4, 9},
    {700, 300, 0, 10},
    {700, 300, -4, 9},
    {700, 300, -7, 7},
    {700, 300, -9, 4},
    {700, 300, -10, 0}
};





//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_CREATE:
        SetTimer(hWnd, 1, 200, 0);
        break;
        case WM_TIMER:
        {
            im1.x += im1.vx;
            im1.y += im1.vy;
            if (im1.x < 25) {
                im1 = { im1.x, im1.y, 10, 0 };
            }
            if (im1.x > 910) {
                im1 = { im1.x, im1.y, -10, 0 };
            }

            im2.x += im2.vx;
            im2.y += im2.vy;
            if (im2.x < 25) {
                im2 = { im2.x, im2.y, 10, 0 };
            }
            if (im2.x > 910) {
                im2 = { im2.x, im2.y, -10, 0 };
            }

            im3.x += im3.vx;
            im3.y += im3.vy;
            if (im3.y < 25) {
                im3 = { im3.x, im3.y, 0, 10 };
            }
            if (im3.y > 390) {
                im3 = { im3.x, im3.y, 0, -10 };
            }
            im4.x += im4.vx;
            im4.y += im4.vy;
            if (im4.y < 25) {
                im4 = { im4.x, im4.y, 0, 10 };
            }
            if (im4.y > 390) {
                im4 = { im4.x, im4.y, 0, -10 };
            }

            dx5 = rand() % 10;
            dy5 = rand() % 21 - 10;

            im5.x += dx5;
            im5.y += dy5;

            int i = 0;
            while (i < NUM_IM_A) {
                imA[i].x += imA[i].vx;
                imA[i].y += imA[i].vy;
                i += 1;
            }

            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT: // стрелка ВЛЕВО
            image1_x -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT: // стрелка ВПРАВО
            image1_x += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN: // стрелка ВНИЗ
            image1_y += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP: // стрелка ВВЕРХ
            image1_y -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        }
        break;
    case WM_LBUTTONDOWN:
    {
        WORD xPos, yPos;

        // Сохраняем координаты курсора мыши
        xPos = LOWORD(lParam);
        yPos = HIWORD(lParam);


        image1_x = xPos;
        image1_y = yPos;
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //Rectangle(hdc, image1_x - 10, image1_y - 10, image1_x + 10, image1_y + 10);
            //Image2(hdc, image1_x, image1_y, RGB(0,255,0));
            Image2(hdc, im1.x, im1.y, RGB(128, 128, 0));
            Image3(hdc, im2.x, im2.y, RGB(128, 128, 0));
            Image6(hdc, im3.x, im3.y, RGB(128, 128, 0));
            Image0(hdc, im4.x, im4.y, RGB(128, 128, 0));
            Image0(hdc, im5.x, im5.y, RGB(255, 128, 0));
            
            int i = 0;
            while (i < NUM_IM_A) {
                Image0(hdc, imA[i].x, imA[i].y, RGB(255, 0, 255));
                i += 1;
            }
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
