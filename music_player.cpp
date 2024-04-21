#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

int main() {
    // Play an audio file
    std::string audioFilePath = "music.wav";
    if (PlaySound(TEXT(audioFilePath.c_str()), NULL, SND_FILENAME) == 0) {
        std::cerr << "Error playing audio file!" << std::endl;
        return -1;
    }

    // Wait for the audio to finish playing
    while (PlaySound(NULL, NULL, SND_PURGE) == TRUE) {
        Sleep(100);
    }

    return 0;
}
