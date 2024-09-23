#include "input_utils.h"

// Implementación de las funciones

bool isKeyDown(int key, bool& wasKeyPressed) 
{
    bool isPressedNow = slGetKey(key);
    if (isPressedNow && !wasKeyPressed) {
        wasKeyPressed = true;
        return true;  // Evento de Key Down
    }
    return false;
}

bool isKeyUp(int key, bool& wasKeyPressed) 
{
    bool isPressedNow = slGetKey(key);
    if (!isPressedNow && wasKeyPressed) {
        wasKeyPressed = false;
        return true;  // Evento de Key Up
    }
    return false;
}

bool isKeyPressed(int key) 
{
    return slGetKey(key);  // La tecla está siendo mantenida
}