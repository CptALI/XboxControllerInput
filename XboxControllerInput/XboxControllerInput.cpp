// XboxControllerInput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <Xinput.h>

#pragma comment(lib, "XInput.lib")

using namespace std;

int main() {

	cout << "Controller Conncettion program" << endl;
	
	
	int controllerId = -1;

	for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(i, &state) == ERROR_SUCCESS)
			controllerId = i;
	}
	cout << "The Controller is connected to port:" << controllerId;

	
	//while (loopCondition) {
	//	Sleep(5);
	//	XINPUT_STATE state;
	//	bool A_button_pressed = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0);
	//	bool Y_button_pressed = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0);
	//	if (A_button_pressed) { cout << "Button A pressed"; }
	//	if (Y_button_pressed) { cout << "Button Y was pressed and exiting the scan loop"; }

	//};
	bool loopCondition = true;
	bool Y_button_pressed = false;
	bool A_button_pressed = false;
	float normLX = 0;
	float normLY = 0;
	while (loopCondition) {

		Sleep(50);
		XINPUT_STATE state;
		XInputGetState(controllerId, &state);
		
		A_button_pressed = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0);
		Y_button_pressed = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0);
		normLX = fmaxf(-1, (float)state.Gamepad.sThumbLX / 32767);
		normLY = fmaxf(-1, (float)state.Gamepad.sThumbLY / 32767);
		
		if (A_button_pressed) {
			//Sleep(100);
			cout << "Button A is pressed"<<endl;
		}

		if (Y_button_pressed) {
			loopCondition = false;
		}

		cout << "normaLX:" << normLX;
		cout << "\tnormaLY" << normLY<< endl;
	}
	

	getchar();
	return 0;
}