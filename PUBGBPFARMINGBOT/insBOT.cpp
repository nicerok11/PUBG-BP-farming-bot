// Version 0.2


#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <Shellapi.h>
#include <ctime>
#include <cpptime.h>




using namespace std;
using namespace CppTime;
const int
coordALLx = 160, coord1MSy = 790, coordTPPy = 865,
coordSTARTy = 1015, coordSETTINGSx = 1840, coordSETTINGSy = 1030,
coordRestartLobbyX = 960, coordRestartLobbyY = 610,
сoordLobbyColorX = 196, сoordLobbyColorY = 98,
need_color1 = 51199, need_color2 = 2106421;
//coordExitToLobbyX = , coordExitToLobbyX = ;  


void LeftClick()
{
	INPUT Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}


int main()
{  

	int ret, pixel_color;

	CppTime::Timer jumpfromplane, exittime, sitdown, checkforlobby;
		


	   



		ret = GetSystemDefaultLangID();
		

		if (ret == 1049) {
			setlocale(0, "Russian");
			std::cout << "Запускаю PUBG" << endl;
		}
		else
			std::cout << "Starting PUBG" << endl;


	


		ShellExecute(NULL, L"open", L"steam://rungameid/578080", NULL, NULL, SW_SHOW);

		Sleep(5000);

		bool running = true;

		while (running) {
			running = false;

			bool check1 = true;
			while (check1 == true)
			{
				HWND menu = FindWindow(TEXT("GxWindowClass"), TEXT("PLAYERUNKNOWN'S BATTLEGROUNDS"));
				HDC menuscr = GetDC(menu);
				pixel_color = GetPixel(menuscr, сoordLobbyColorX, сoordLobbyColorY);


				if (need_color1 == pixel_color) {

					Sleep(1000);

					std::cout << "Starting Match..." << endl;
					SetCursorPos(coordALLx, coord1MSy);
					Sleep(500);
					LeftClick();
					SetCursorPos(coordALLx, coordTPPy);
					Sleep(500);
					LeftClick();
					SetCursorPos(coordALLx, coordSTARTy);
					Sleep(500);
					LeftClick();

					check1 = false;
				}
			}

			Sleep(2000);

			HWND loading = FindWindow(TEXT("GxWindowClass"), TEXT("PLAYERUNKNOWN'S BATTLEGROUNDS"));
			HDC loadscr = GetDC(loading);
			pixel_color = GetPixel(loadscr, 300, 300);

			if (ret == 1049)
				std::cout << "Матч загружается" << endl;
			else
				std::cout << "Match is loading" << endl;

			check1 = true;

			while (check1) {

				if (need_color2 != pixel_color) {

					if (ret == 1049)
						std::cout << "Матч в процессе" << endl;
					else
						std::cout << "Match is loaded" << endl;
					check1 = false;
				}

			}
			jumpfromplane.add(std::chrono::seconds(90), [](CppTime::timer_id) {

				INPUT ip;
				ip.type = INPUT_KEYBOARD;
				ip.ki.wScan = 0;
				ip.ki.time = 0;
				ip.ki.dwExtraInfo = 0;

				ip.ki.wVk = 'F';
				ip.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &ip, sizeof(INPUT));

				Sleep(20);

				ip.ki.wVk = 'F';
				ip.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &ip, sizeof(INPUT));

				std::cout << "Just dropped from plane!";
				bool check1 = false;
			});
			std::this_thread::sleep_for(std::chrono::seconds(2));

			if (ret == 1049)
				std::cout << "Не даю тебе умереть в воде" << endl;
			else
				std::cout << "Don't let you to die if you are in water " << endl;


			sitdown.add(std::chrono::seconds(240), [](CppTime::timer_id) {

				INPUT ip;
				ip.type = INPUT_KEYBOARD;
				ip.ki.wScan = 0;
				ip.ki.time = 0;
				ip.ki.dwExtraInfo = 0;

				ip.ki.wVk = 'Z';
				ip.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &ip, sizeof(INPUT));

				Sleep(20);

				ip.ki.wVk = 'Z';
				ip.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &ip, sizeof(INPUT));

				std:cout << "Just falled down" << endl;

				bool check1 = true;


			});
			std::this_thread::sleep_for(std::chrono::seconds(2));


			exittime.add(std::chrono::seconds(360), [](CppTime::timer_id) {

				INPUT ip;
				ip.type = INPUT_KEYBOARD;
				ip.ki.wScan = 0;
				ip.ki.time = 0;
				ip.ki.dwExtraInfo = 0;

				ip.ki.wVk = VK_ESCAPE;
				ip.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &ip, sizeof(INPUT));

				ip.ki.wVk = VK_ESCAPE;
				ip.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &ip, sizeof(INPUT));

				SetCursorPos(coordRestartLobbyX, coordRestartLobbyY);
				Sleep(500);
				LeftClick();
				SetCursorPos(841, 576);
				Sleep(500);
				LeftClick();
				Sleep(500);
				LeftClick();


				std::cout << "Succesfully exit from match to lobby" << endl;
			});
			std::this_thread::sleep_for(std::chrono::seconds(2));


			checkforlobby.add(std::chrono::seconds(365), [](CppTime::timer_id) {

				HWND menu = FindWindow(TEXT("GxWindowClass"), TEXT("PLAYERUNKNOWN'S BATTLEGROUNDS"));
				HDC menuscr = GetDC(menu);
				int pixel_color = GetPixel(menuscr, сoordLobbyColorX, сoordLobbyColorY);

				if (need_color1 == pixel_color) {
					bool	check1 = true;
					bool    running = true;
			
				}

			});
			std::this_thread::sleep_for(std::chrono::seconds(2));


			while (check1 != true) {

				INPUT ip;
				ip.type = INPUT_KEYBOARD;
				ip.ki.wScan = 0;
				ip.ki.time = 0;
				ip.ki.dwExtraInfo = 0;

				ip.ki.wVk = VK_SPACE;
				ip.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &ip, sizeof(INPUT));

				Sleep(65);

				ip.ki.wVk = 'W';
				ip.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &ip, sizeof(INPUT));

			}

			
			  

			}




		std::cin.get();
		return 0;


}

