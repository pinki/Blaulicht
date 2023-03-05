#include <Arduino.h>

#define LED_PIN_1     12
#define LED_PIN_2     13

#define BLINK_COUNT    3
#define SHORT_DELAY   50
#define LONG_DELAY   200

// #define DEEP_SLEEP


uint8_t ledPins[] = { LED_PIN_1, LED_PIN_2 };

void setup() {
  for (uint8_t ledPin : ledPins) {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
  }
}

void loop() {
  for (uint8_t ledPin : ledPins) {
    for (uint8_t i = 0; i < BLINK_COUNT; i++) {
      digitalWrite(ledPin, LOW);
      delay(SHORT_DELAY);
      digitalWrite(ledPin, HIGH);
      delay(SHORT_DELAY);
    }

#ifdef DEEP_SLEEP
    if (ledPin != ledPins[sizeof(ledPins) - 1])
#endif
    delay(LONG_DELAY);
  }

#ifdef DEEP_SLEEP
  esp_sleep_enable_timer_wakeup(LONG_DELAY * 1000);
  esp_deep_sleep_start();

  delay(10000);
#endif
}