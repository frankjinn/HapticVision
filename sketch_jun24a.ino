using namespace std;

#define MAXOUT 180
#define MINOUT 50

//Up Right Down Left
int outputPins[4] = {11, 10, 9, 6};
int arrayLen = 4;
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  for (int pinIdx = 0; pinIdx <= arrayLen; pinIdx++) {
    pinMode(outputPins[pinIdx], OUTPUT);
  }

  for (int pinIdx = 0; pinIdx <= arrayLen; pinIdx++) {
    int intensity = MINOUT;
    int halfLoop = 0;

    while (halfLoop < 2) {
      analogWrite(outputPins[pinIdx], intensity);
      intensity = intensity + fadeAmount;
      // reverse the direction of the fading at the ends of the fade:
      if (intensity <= MINOUT || intensity >= MAXOUT) {
        fadeAmount = -fadeAmount;
        halfLoop += 1;
      }
      delay(30);
    }
    analogWrite(outputPins[pinIdx], 0);
    delay(100);
  }
}

// the loop routine runs over and over again forever:
void loop() {
}

void pulse(int outputPin) {
  int intensity = MINOUT;
  int halfLoop = 0;

  while (halfLoop <= 2) {
    analogWrite(outputPin, intensity);
    intensity = intensity + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
    if (intensity <= MINOUT || intensity >= MAXOUT) {
      fadeAmount = -fadeAmount;
      halfLoop += 1;
    }
    delay(30);
  }
}