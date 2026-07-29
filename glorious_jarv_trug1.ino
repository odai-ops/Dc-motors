#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);

  int currentAngle = 0;
  int sweepStep = 5;

  // تشغيل حركة الـ Sweep لمدة ثانيتين (2000 مللي ثانية)
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    servo1.write(currentAngle);
    servo2.write(currentAngle);
    servo3.write(currentAngle);
    servo4.write(currentAngle);
    delay(15);

    currentAngle += sweepStep;
    if (currentAngle >= 180 || currentAngle <= 0) {
      sweepStep = -sweepStep;
    }
  }

  // بعد انتهاء الثانيتين، التوقف والتثبيت على 90 درجة
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
}

void loop() {
  // تبقى المحركات على زاوية 90 درجة
}