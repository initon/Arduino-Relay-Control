const express = require('express');
const { SerialPort } = require('serialport');

const app = express();
const port = 3000;

// Настройка последовательного порта (укажите ваш порт)
const serialPort = new SerialPort({
  path: 'COM7', // указать порт
  baudRate: 9600,
});

// Middleware для парсинга JSON
app.use(express.json());
app.use(express.static('public')); // Для статических файлов (HTML)

app.post('/restart', (req, res) => {
  const command = req.body.command;

  if (['RESTART_RELAY1', 'RESTART_RELAY2', 'RESTART_RELAY3', 'RESTART_RELAY4'].includes(command)) {
    serialPort.write(`${command}\n`, (err) => {
      if (err) {
        return res.status(500).send('Error on write: ' + err.message);
      }
      res.send(`Команда отправлена: ${command}`);
    });
  } else {
    res.status(400).send('Неизвестная команда');
  }
});

serialPort.on('open', () => {
  console.log('Последовательный порт открыт...');
});

serialPort.on('error', (err) => {
  console.error('Ошибка: ', err.message);
});

app.listen(port, () => {
  console.log(`Сервер запущен на http://localhost:${port}`);
});