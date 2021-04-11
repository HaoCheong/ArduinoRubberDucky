#include <Keyboard.h>

void setup() {
  Keyboard.begin();
  startBuffer(); //Buffer to unplug or upload
  desktopStart();
  ducky();
}

// This is a 10 second count down timer which delay the execution of the file
// Allows time to upload a new script or stop a script to the system
// Do NOT edit
void startBuffer() {
  for (int x = 0; x < 10; x++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

//Here is where the payload program will exist
void ducky() {
  //Gotta use `n for new line
  //Create a file which write a batch file
  int keyToPress[2] = {KEY_LEFT_GUI,114};
  String directoryToStore = String("C:\\Users\\Hao\\Desktop");
  String data = String("@echo off `n echo.>`\"C:\\Users\\Hao\\Desktop\\test_folder\\malFile1.txt`\"");
  String fileName = String("batchMal.bat");
  
  simulType(keyToPress);
  delay(1000);
  Keyboard.print("powershell");
  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("cd " + directoryToStore);
  delay(1000);
  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("echo \"" + data + "\" > " + fileName);
  delay(1000);
  typeKey(KEY_RETURN);
  
  //Run Batch File
}

//Type and release a chosen key
void typeKey(int key)
{
  Keyboard.press(key);
  delay(100);
  Keyboard.release(key);
}

//Deals with multiple key presses, will press multiple keys together
//Ex. int keysToSimulPress[3] = {KEY_LEFT_CTRL,KEY_LEFT_ALT,KEY_DELETE};
void simulType(int keys[]) {
  int numOfKeys = sizeof(keys);
  for (int i = 0; i <= numOfKeys; i++) {
    //Serial.print(keys[i]);
    
    Keyboard.press(keys[i]);
    delay(10);
  }
  Keyboard.releaseAll();
}

//Forces a users system to look at the desktop
//Minimizes all the windows
void desktopStart() {
  delay(100);
  int dStartKeys[2] = {KEY_LEFT_GUI,109};
  simulType(dStartKeys);
  delay(100);
}

//Signifier that the payload has completed execution
void endBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void loop() {
  endBlink();
}
