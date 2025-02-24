// Определяем пины для реле
const int relay1Pin = 2; // Пин для 1-го реле
const int relay2Pin = 3; // Пин для 2-го реле
const int relay3Pin = 4; // Пин для 3-го реле
const int relay4Pin = 5; // Пин для 4-го реле

void setup() {
  // Настраиваем пины как выходы
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
  
  // Инициализация последовательного порта
  Serial.begin(9600);
}

void loop() {
  // Проверяем, есть ли доступные данные для чтения
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Читаем команду до символа новой строки
    processCommand(command); // Обрабатываем команду
  }
}

// Функция для обработки команд
void processCommand(String command) {
  if (command == "RESTART_RELAY1") {
    digitalWrite(relay1Pin, HIGH); // Выключаем 1-е реле
    Serial.println("Relay 1 is OFF, restarting...");
    delay(5000); // Ждем 5 секунд
    digitalWrite(relay1Pin, LOW); // Включаем 1-е реле снова
    Serial.println("Relay 1 is ON");
  } 
  else if (command == "RESTART_RELAY2") {
    digitalWrite(relay2Pin, HIGH); // Выключаем 2-е реле
    Serial.println("Relay 2 is OFF, restarting...");
    delay(5000); // Ждем 5 секунд
    digitalWrite(relay2Pin, LOW); // Включаем 2-е реле снова
    Serial.println("Relay 2 is ON");
  } 
  else if (command == "RESTART_RELAY3") {
    digitalWrite(relay3Pin, HIGH); // Выключаем 3-е реле
    Serial.println("Relay 3 is OFF, restarting...");
    delay(5000); // Ждем 5 секунд
    digitalWrite(relay3Pin, LOW); // Включаем 3-е реле снова
    Serial.println("Relay 3 is ON");
  } 
  else if (command == "RESTART_RELAY4") {
    digitalWrite(relay4Pin, HIGH); // Выключаем 4-е реле
    Serial.println("Relay 4 is OFF, restarting...");
    delay(5000); // Ждем 5 секунд
    digitalWrite(relay4Pin, LOW); // Включаем 4-е реле снова
    Serial.println("Relay 4 is ON");
  } 
  else {
    Serial.println("Unknown command: " + command); // Сообщение об ошибке для неизвестной команды
  }
}