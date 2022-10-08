#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <tchar.h>

#define ID_LABEL 100
#define ID_BTNZERO 101
#define ID_BTNONE 102
#define ID_BTNTWO 103
#define ID_BTNTHREE 104
#define ID_BTNFOURTH 105
#define ID_BTNFIVE 106
#define ID_BTNSIX 107
#define ID_BTNSEVEN 108
#define ID_BTNEIGHT 109
#define ID_BTNNINE 110
#define ID_BTNSUM 111
#define ID_BTNREST 112
#define ID_BTNMULT 113
#define ID_BTNDIV 114
#define ID_BTNCE 115
#define ID_BTNC 116
#define ID_BTNX 117
#define ID_BTNPOINT 118
#define ID_BTNRESULT 119

using std::string;

// Global variables
// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");
// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Calculator");

char display[256] = "";
char result[256] = "";

void hidenConsola(){
	HWND console;
	AllocConsole();
	console = FindWindowA(szWindowClass, NULL);
	ShowWindow(console, 0);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc;
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = CreateSolidBrush(RGB(21, 232, 189));
	wc.lpszClassName = szWindowClass;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	wc.style		 = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra 	 = 0;
	wc.cbWndExtra	 = 0;
	wc.lpszMenuName	 = NULL;
	
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		szWindowClass, szTitle,
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		340, 550,
		NULL, NULL, hInstance, NULL
	);
	
	// Fila 1
	CreateWindow(
		"Static",
		display,
		WS_VISIBLE|WS_CHILD|SS_NOTIFY,
		10, 10,
		300, 100,
		hwnd, (HMENU)ID_LABEL, hInstance, NULL
	);
	
	// Fila 6
	CreateWindowEx(
		0, "BUTTON", "0",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		10, 431,
		65, 69,
		hwnd, (HMENU)ID_BTNZERO, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", ".",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		90, 431,
		65, 69,
		hwnd, (HMENU)ID_BTNPOINT, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "=",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		165, 431,
		145, 69,
		hwnd, (HMENU)ID_BTNRESULT, hInstance, NULL
	);
	
	// Fila 5
	CreateWindowEx(
		0, "BUTTON", "1",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		10, 357,
		65, 69,
		hwnd, (HMENU)ID_BTNONE, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "2",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		90, 357,
		65, 69,
		hwnd, (HMENU)ID_BTNTWO, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "3",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		165, 357,
		65, 69,
		hwnd, (HMENU)ID_BTNTHREE, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "+",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		245, 357,
		65, 69,
		hwnd, (HMENU)ID_BTNSUM, hInstance, NULL
	);
	
	// Fila 4
	CreateWindowEx(
		0, "BUTTON", "4",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		10, 283,
		65, 69,
		hwnd, (HMENU)ID_BTNFOURTH, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "5",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		90, 283,
		65, 69,
		hwnd, (HMENU)ID_BTNFIVE, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "6",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		165, 283,
		65, 69,
		hwnd, (HMENU)ID_BTNSIX, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "-",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		245, 283,
		65, 69,
		hwnd, (HMENU)ID_BTNREST, hInstance, NULL
	);
	
	// Fila 3
	CreateWindowEx(
		0, "BUTTON", "7",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		10, 209,
		65, 69,
		hwnd, (HMENU)ID_BTNSEVEN, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "8",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		90, 209,
		65, 69,
		hwnd, (HMENU)ID_BTNEIGHT, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "9",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		165, 209,
		65, 69,
		hwnd, (HMENU)ID_BTNNINE, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "*",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		245, 209,
		65, 69,
		hwnd, (HMENU)ID_BTNMULT, hInstance, NULL
	);
	
	// Fila 2
	CreateWindowEx(
		0, "BUTTON", "CE",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		10, 135,
		65, 69,
		hwnd, (HMENU)ID_BTNCE, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "C",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		90, 135,
		65, 69,
		hwnd, (HMENU)ID_BTNC, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "X",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		165, 135,
		65, 69,
		hwnd, (HMENU)ID_BTNX, hInstance, NULL
	);
	
	CreateWindowEx(
		0, "BUTTON", "/",
		ES_CENTER|WS_CHILD|WS_VISIBLE,
		245, 135,
		65, 69,
		hwnd, (HMENU)ID_BTNDIV, hInstance, NULL
	);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!", MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	static HINSTANCE hInst;
	
	switch(Message) {

		/* create the instance */
		case WM_CREATE: {
			/* Here is where we create the button in etc.. */
			hInst = ((LPCREATESTRUCT)lParam) -> hInstance;
			break;
		}
		
		case WM_COMMAND: {
			switch(LOWORD(wParam)) {
				case ID_BTNZERO: {
					display[strlen(display)] += '0';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNONE: {
					display[strlen(display)] += '1';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNTWO: {
					display[strlen(display)] += '2';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNTHREE: {
					display[strlen(display)] += '3';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNFOURTH: {
					display[strlen(display)] += '4';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNFIVE: {
					display[strlen(display)] += '5';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNSIX: {
					display[strlen(display)] += '6';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNSEVEN: {
					display[strlen(display)] += '7';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNEIGHT: {
					display[strlen(display)] += '8';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNNINE: {
					display[strlen(display)] += '9';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNSUM: {
					display[strlen(display)] += '+';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNREST: {
					display[strlen(display)] += '-';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNMULT: {
					display[strlen(display)] += '*';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNDIV: {
					display[strlen(display)] += '/';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNPOINT: {
					display[strlen(display)] += '.';	
					CreateWindow("Static", display, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNRESULT: {
					itoa(strlen(display), result, 256);
					CreateWindow("Static", result, WS_VISIBLE|WS_CHILD|SS_NOTIFY, 10, 10, 300, 100, hwnd, (HMENU)ID_LABEL, hInst, NULL);
					break;
				}
				case ID_BTNCE: {
					//display += '0';
					break;
				}
				case ID_BTNC: {
					//display += '0';
					break;
				}
				case ID_BTNX: {
					//display += '0';
					break;
				}
			}
			break;
		}
		
		case WM_CTLCOLORSTATIC: {
			break;
		}

		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}

		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

