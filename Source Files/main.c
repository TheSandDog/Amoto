#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib") // Link with Winmm.lib to use PlaySoundW

void SendWarning(const wchar_t* Title, const wchar_t* Description) {
    MessageBoxW(NULL, Description, Title, MB_OK | MB_ICONWARNING);
}

void SendError(const wchar_t* Title, const wchar_t* Description) {
    MessageBoxW(NULL, Description, Title, MB_OK | MB_ICONERROR);
}

time_t t;
void SendRandMouse() {
    for (int i = 0; i < 10000; i++) {
        SetCursorPos(rand() % 4000, rand() % 4000);
        Sleep(5); // Add a short delay to see the mouse movement
    }
}

int main() {
    srand((unsigned)time(&t));

    SendError(L"Hello I am Bonzo", L"");
    SendError(L"Let's play together", L"");
    SendRandMouse();
    SendWarning(L"I'm not done with you yet", L"");
    SendWarning(L"I'm just having a simple warm-up", L"");

    const wchar_t filename[] = L"laugh.mp3";
    wchar_t path[MAX_PATH];

    DWORD result = SearchPathW(NULL, filename, NULL, MAX_PATH, path, NULL);

    if (result > 0) {
        wprintf(L"Path of the file \"laugh.mp3\": %ls\n", path);
        //PlaySoundW(path, NULL, SND_FILENAME | SND_ASYNC);
        //Sleep(5000); // Play sound for 5 seconds (adjust as needed)
        //PlaySoundW(NULL, NULL, SND_PURGE); // Stop the sound
    }
    else {
        wprintf(L"File \"laugh.mp3\" not found.\n");
    }

    return 0;
}
