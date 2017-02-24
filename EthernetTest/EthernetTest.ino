#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDA, 0x02 };
IPAddress ip(191,11,1,2); //<<< ENTER YOUR IP ADDRESS HERE!!!

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup()
{
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
}

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String receivedText = "";
    while (client.connected()) {
      if (client.available()) {
        
        char c = client.read();
        Serial.print(c);
        receivedText.concat(c);
        
        if (c == '\n')
        {
          client.println("RECEIVED:" + receivedText);
          break;
        }

      }
      
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    //client.stop();
  }
}
