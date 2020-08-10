#include <AccelStepper.h>

AccelStepper Stepper1(1,11,10); //использует пин 12 и 13 для dir и step, 1 - режим "external driver" (A4988)
int dir = 1; //используется для смены направления

void setup() {
  Stepper1.setMaxSpeed(3000); //устанавливаем максимальную скорость вращения ротора двигателя (шагов/секунду)
  Stepper1.setAcceleration(13000); //устанавливаем ускорение (шагов/секунду^2)
}

void loop() {
  if(Stepper1.distanceToGo()==0){ //проверка, отработал ли двигатель предыдущее движение
    Stepper1.move(1600*dir); //устанавливает следующее перемещение на 1600 шагов (если dir равен -1 будет перемещаться -1600 -> противоположное направление)
    dir = dir*(-1); //отрицательное значение dir, благодаря чему реализуется вращение в противоположном направлении
    delay(1000); //задержка на 1 секунду
  }
  Stepper1.run(); //запуск шагового двигателя. Эта строка повторяется вновь и вновь для непрерывного вращения двигателя
}
