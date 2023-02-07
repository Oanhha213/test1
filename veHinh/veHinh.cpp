// veHinh.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "veHinh.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HMENU hMenu;
// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_VEHINH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VEHINH));

    MSG msg;

    // Main message loop:
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VEHINH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_VEHINH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1));
   HWND hWnd = CreateWindowW(szWindowClass, TEXT("Vẽ Hình"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, hMenu, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT pt[1000];
    static int x, y, m = 90, s = 0;
    static int n = 0;
    static TCHAR text[100];
    static int luu = -1;
    static int luumn = -1;
    static int luudv = -1;
    //Vẽ BTVN
    static int xClient, yClient;
    //Vẽ dùng con trỏ chuột
    HDC hdc;
    static int x1, y1;
    //POINT point[8] = { {300,100},{350,200},{450,250},{350,300},{300,400},{250,300},{150,250},{250,200} };
    //POINT pT[4];
    //POINT pt[3];
    POINT PT[8];
    HPEN hPen;
    HBRUSH hBrush;
    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, 9999, 1000, NULL);
        break;
    case WM_TIMER:
        if (s == 0 && m == 0) {
            MessageBox(NULL, TEXT("Hết giờ"), TEXT("Thông báo"), MB_OK | MB_ICONINFORMATION);
            KillTimer(hWnd, NULL);
        }
        if (s > 0 && s <= 59) {
            s--;
        }
        else {
            if (s == 0) {
                m--;
                s = 59;
            }
        }
        wsprintf(text, L"Thời gian %d: %d", m, s);
        hdc = GetDC(hWnd);
        TextOut(hdc, 0, 0, text, 100);
        ReleaseDC(hWnd, hdc);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {

            case ID_Exit:
                if(MessageBox(NULL, TEXT("Bạn có muốn thoát không?"), TEXT("Thông báo"), MB_ICONQUESTION | MB_YESNO) == IDYES)
                DestroyWindow(hWnd);
                break;
            case ID_Rec:
                luu = 0;
                break;
            case ID_Ellipse:
                luu = 1;
                break; 
            case ID_Free:
                luu = 2;
                break;
            case ID_Star:
                luu = 3;
                break;
            case ID_Green:
                luumn = 0;
                break;
            case ID_Blue:
                luumn = 1;
                break;
            case ID_Red:
                luudv = 0;
                break;
            case ID_Turquoise:
                luudv = 1;
                break;
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
    //Vẽ BTVN
    case WM_SIZE:
        xClient = LOWORD(lParam);
        yClient = HIWORD(lParam);
        return 0;
    //Vẽ bằng con trỏ chuột
    /*
    */
    case WM_LBUTTONDOWN:
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        hdc = GetDC(hWnd);
        if (luu == 2) {
            pt[n].x = x;
            pt[n].y = y;
            n++;
            SetPixel(hdc, x, y, RGB(0, 0, 0));
            /*
            if (luudv == 0) {
                SetPixel(hdc, x, y, RGB(255, 0, 0));
            }
            else if (luudv == 1) {
                SetPixel(hdc, x, y, RGB(64, 224, 208));    
            }
            else {
                SetPixel(hdc, x, y, RGB(0,0,0));
            }
            */
        }
        ReleaseDC(hWnd, hdc);
        break;
    case WM_RBUTTONDOWN:
        hdc = GetDC(hWnd);
        Polyline(hdc, pt, n);
        ReleaseDC(hWnd, hdc);
        break;
    case WM_LBUTTONUP:
        x1 = LOWORD(lParam);
        y1 = HIWORD(lParam);
        hdc = GetDC(hWnd);
        /*
        //Ellipse(hdc, x, y, x1, y1);
        //Hình thoi
        pT[0].x = (x + x1) / 2;
        pT[0].y = y;
        pT[1].x = x1;
        pT[1].y = (y + y1) / 2;
        pT[2].x = (x + x1) / 2;
        pT[2].y = y1;
        pT[3].x = x;
        pT[3].y = (y + y1) / 2;
        //Polygon(hdc, pT, 4);
        //tam giác vuông
        pt[0].x = x;
        pt[0].y = y;
        pt[1].x = x1;
        pt[1].y = y1;
        pt[2].x = x;
        pt[2].y = y1;
        //Polygon(hdc, pt, 3);
        PT[0].x = x;
        PT[0].y = y;
        hPen = CreatePen(PS_DASH, 1, RGB(20,100,70));
        //hBrush = CreateHatchBrush(HS_CROSS, RGB(200, 100, 100));
        hBrush = CreateSolidBrush(RGB(20, 200, 150));
        */
        if (luu == 0) {
            if (luumn == 0) {
                hBrush = CreateSolidBrush(RGB(0,255,0));
                SelectObject(hdc, hBrush);
                if (luudv == 0) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                    SelectObject(hdc, hPen);
                }
                else if (luudv == 1) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(64, 224, 208));
                    SelectObject(hdc, hPen);
                }
            }
            else if (luumn == 1) {
                hBrush = CreateSolidBrush(RGB(0, 0, 255));
                SelectObject(hdc, hBrush);
                if (luudv == 0) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                    SelectObject(hdc, hPen);
                }
                else if (luudv == 1) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(64, 224, 208));
                    SelectObject(hdc, hPen);
                }
            }
            Rectangle(hdc, x, y, x1, y1);
        }
        if (luu == 1) {
            if (luumn == 0) {
                hBrush = CreateSolidBrush(RGB(0,255,0));
                SelectObject(hdc, hBrush);
                if (luudv == 0) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                    SelectObject(hdc, hPen);
                }
                else if (luudv == 1) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(64, 224, 208));
                    SelectObject(hdc, hPen);
                }
            }
            else if (luumn == 1) {
                hBrush = CreateSolidBrush(RGB(0, 0, 255));
                SelectObject(hdc, hBrush);
                if (luudv == 0) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                    SelectObject(hdc, hPen);
                }
                else if (luudv == 1) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(64, 224, 208));
                    SelectObject(hdc, hPen);
                }
            }
            Ellipse(hdc, x, y, x1, y1);
        }
        //Ellipse(hdc, x, y, x1, y1);
        if (luu == 3) {
            if (luumn == 0) {
                hBrush = CreateSolidBrush(RGB(0, 255, 0));
                SelectObject(hdc, hBrush);
                if (luudv == 0) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                    SelectObject(hdc, hPen);
                }
                else if (luudv == 1) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(64, 224, 208));
                    SelectObject(hdc, hPen);
                }
            }
            else if (luumn == 1) {
                hBrush = CreateSolidBrush(RGB(0, 0, 255));
                SelectObject(hdc, hBrush);
                if (luudv == 0) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                    SelectObject(hdc, hPen);
                }
                else if (luudv == 1) {
                    hPen = CreatePen(PS_SOLID, 2, RGB(64, 224, 208));
                    SelectObject(hdc, hPen);
                }
            }
            PT[0].x = (x + x1) / 2;
            PT[0].y = y;
            PT[1].x = (3*x+5*x1)/8;
            PT[1].y = (5*y + 3*y1) / 8;
            PT[2].x = x1;
            PT[2].y = (y+y1)/2;
            PT[3].x = (3*x+5*x1)/8;
            PT[3].y = (3*y + 5*y1) / 8;
            PT[4].x = (x+x1)/2;
            PT[4].y = y1;
            PT[5].x = (5 * x + 3 * x1) / 8;
            PT[5].y = (3 * y + 5 * y1) / 8;
            PT[6].x = x;
            PT[6].y = (y+y1)/2;
            PT[7].x = (5 * x + 3 * x1) / 8;
            PT[7].y = (5 * y + 3 * y1) / 8;
            Polygon(hdc, PT, 8);
        }
        ReleaseDC(hWnd, hdc);
        break;
        
    case WM_PAINT:
        {
        
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            //Vẽ điểm
            /*
            for (int i = 100;i <= 250;i++) {
                SetPixel(hdc, i, 100, RGB(255, 0, 0));
            }
            */
            //Vẽ đoạn thẳng
            //MoveToEx(hdc, 100, 200, NULL);
            //LineTo(hdc, 250, 200);
            //Vẽ đường gấp khúc
            //Polyline(hdc, point, 3);
            //Polygon(hdc, point, 8);
            //Vẽ hình chữ nhật
            //Rectangle(hdc, 100, 100, 300, 200);
            //Hình chữ nhật góc tròn
            //RoundRect(hdc, 100, 100, 400, 400, 50, 50);
            //Hình elip
            //Ellipse(hdc, 100, 300, 300, 400);
            //Hình cung
            //Arc(hdc, 250, 250, 500, 450, 300, 250, 250, 400);
            //Hình quạt
            //Pie(hdc, 250, 250, 600, 450, 300, 250,250, 400);
            //Hình Chord
            //Chord(hdc, 250, 250, 600, 450, 300, 250, 250, 400);
            //BTVN
            /*
            Rectangle(hdc, 120, 69, 642, 372);
            MoveToEx(hdc, 0, 0, NULL);
            LineTo(hdc, 763, 440);
            MoveToEx(hdc, 763, 0, NULL);
            LineTo(hdc, 0, 440);
            Ellipse(hdc, 120, 69, 642, 372);
            RoundRect(hdc, 240, 138, 522, 303, 110, 70);
            */
            /*
            Rectangle(hdc, xClient/8 ,yClient/8, 7*xClient/8,7*yClient/8);
            MoveToEx(hdc, 0, 0, NULL);
            LineTo(hdc, xClient, yClient);
            MoveToEx(hdc, 0, yClient, NULL);
            LineTo(hdc, xClient, 0);
            Ellipse(hdc, xClient / 8, yClient / 8, 7 * xClient / 8, 7 * yClient / 8);
            RoundRect(hdc, xClient / 4, yClient / 4, 3 * xClient / 4, 3 * yClient / 4, xClient / 4, yClient / 4);
            */
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        //DeleteObject(hPen);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
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
