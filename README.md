# CoffeeMachine


# Coffee Machine Emulator

Опис проекту
Цей проект є емуляцією роботи кавомашини з реалізацієб різних станів та ієрархії напоїв.

Ієрархія напоїв:
**DrinkProgram** (базовий клас):.
**Coffee**: абстрактний клас для кавових напоїв з похідними класами:
- Espresso
- Cappuccino
**Tea**: абстрактний клас для чаю з похідними класами:
  - BlackTea – використання води при 95°C
  - GreenTea – використання води при 80°C

Логіка роботи CoffeeGrainsContainer:
- Перевірка наявності зерен, їх використання (з можливістю додавання логіки подрібнення) та очищення відходів.
- Різні порції зерен можуть використовуватись для різних типів кави.

Стан кавомашини
- **CoffeeMachineState (базовий клас)** 
Стани:
  - **IdleState** – основний режим роботи.
  - **CleaningState** – режим очищення машини.
  - **SleepState** – режим енергозбереження (при довгій бездіяльності).

Резервуари з єдиним інтерфейсом:
- **Reservoir (абстрактний клас):** методи перевірки об'єму, використання та заправки.
- **WaterReservoir** та **MilkReservoir** реалізують спільний інтерфейс з відповідною логікою.

Додаткові механіки
- Автоматичне очищення після певної кількості приготувань.
- Режим сну, коли машина не використовується тривалий час.
- Легке додавання нових напоїв (какао, айс лате, матча тощо).
