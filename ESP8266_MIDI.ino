/* Configurações de MCP3008 */
#include <MCP3008.h>

/**
 * Configurações de Pins
 */
#define MCP3008_CLOCK_PIN 2
#define MCP3008_MISO_PIN 5
#define MCP3008_MOSI_PIN 4
#define MCP3008_CS_PIN 0

/**
 * Configurações de MCP3008
 */
MCP3008 adc(MCP3008_CLOCK_PIN, MCP3008_MOSI_PIN, MCP3008_MISO_PIN, MCP3008_CS_PIN);

/**
 * Flags Pins
 */
const boolean flagMCP3008 = true;

/**
 * Tempos de Atualização
 */
long lastTemp = 0;

/**
 * Setup
 */
void setup() {
  
}

/**
 * Loop
 */
void loop() {
  
  if(flagMCP3008){
    readMCP3008();
  }
}

/**
 * readMCP3008
 */
void readMCP3008() {
  long now = millis();
  if (now - lastTemp > 1000) {
    lastTemp = now;
    int val =0;
    val = adc.readADC(7);
    Serial.print("var7: "); 
    Serial.println(val);
    val = adc.readADC(6);
    Serial.print("var6: ");
    Serial.println(val);
    val = adc.readADC(5);
    Serial.print("var5: ");
    Serial.println(val);
    val = adc.readADC(4);
    Serial.print("var4: ");
    Serial.println(val);
    val = adc.readADC(3);
    Serial.print("var3: ");
    Serial.println(val);
    val = adc.readADC(2);
    Serial.print("var2: ");
    Serial.println(val);
    val = adc.readADC(1);
    Serial.print("var1: ");
    Serial.println(val);
    val = adc.readADC(0);
    Serial.print("var0: ");
    Serial.println(val);
    
    char resultMCP3008[200];    
    int note = 53;
    int velocity = 100;
    int channel = 1;
    char* clientM = "Performer";

    if (adc.readADC(7) >500){
      snprintf(resultMCP3008, 200, "{\"note\": %d, \"velocity\": %d, \"channel\": %d, \"client\": \"%s\"}", note, velocity, channel, clientM);
      Serial.println(resultMCP3008);      
    }
    if (adc.readADC(6) >500){
      snprintf(resultMCP3008, 200, "{\"note\": %d, \"velocity\": %d, \"channel\": %d, \"client\": \"%s\"}", (note+1), velocity, channel, clientM);
      Serial.println(resultMCP3008);      
    }
    if (adc.readADC(5) >500){
      snprintf(resultMCP3008, 200, "{\"note\": %d, \"velocity\": %d, \"channel\": %d, \"client\": \"%s\"}", (note+2), velocity, channel, clientM);
      Serial.println(resultMCP3008);
    }    
  }
}
