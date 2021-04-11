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
  int keyToPress[2] = {KEY_LEFT_GUI,114}; //Opens "Run"
  int saveKeys[2] = {KEY_LEFT_CTRL,115}; //Ctrl-S
  int openKeys[2] = {KEY_LEFT_CTRL,111}; //Ctrl-O
  simulType(keyToPress);
  
  //Get wallpaper
  delay(500);
  String wallPaperUrl = String("https://wallpaperaccess.com/full/1254721.jpg");
  delay(500);
  
  Keyboard.print(wallPaperUrl);
  typeKey(KEY_RETURN);
  delay(3000);
  simulType(saveKeys);
  
  //Save it
  delay(500);
  String locationToStorePath = String("C:\\Users\\Hao\\Desktop\\wallpaper.jpg"); //Addtional back slash needed
  Keyboard.print(locationToStorePath);
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  
  //Open Paint
  typeKey(KEY_LEFT_GUI);
  delay(500);
  Keyboard.print("paint");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  
  //Open Image in paint
  simulType(openKeys);
  delay(500);
  Keyboard.print(locationToStorePath);
  delay(500);
  typeKey(KEY_RETURN);
  
  //Set image as wallpaper with paint
  typeKey(KEY_LEFT_ALT);
  typeKey(102);
  typeKey(98);
  
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
