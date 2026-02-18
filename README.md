# OOP Design Patterns in C

Учебный проект по реализации паттернов проектирования на языке C
с эмуляцией принципов ООП через структуры и указатели на функции.

## Реализованные паттерны

### Creational
- Factory Method  
- Singleton  
- Builder  
- Abstract Factory  

### Structural
- Adapter  
- Facade  
- Bridge  
- Decorator  
- Composite  
- Proxy  
- Flyweight  

### Behavioral
- Strategy  
- Observer  
- Template Method  
- Command  
- Chain of Responsibility  
- Iterator  
- State  
- Mediator  
- Memento  
- Interpreter  
- Visitor  

### Структуры данных
- Stack  

📦 Порождающие паттерны (Creational)
Factory Method
Singleton
Builder
Abstract Factory

🧱 Структурные паттерны (Structural)
Adapter
Facade
Bridge
Decorator
Composite
Proxy
Flyweight

💬 Поведенческие паттерны (Behavioral)
Strategy
Observer
Template Method
Command
Chain of Responsibility
Iterator
State
Mediator
Memento
Interpreter
Visitor

Указатели на функции
Это очень ценная учебная работа, так как показывает, как можно применять ООП-паттерны в языке, который изначально не предназначен для объектно-ориентированного программирования.
Команда сборки clang *.c -o app -Wall -Wextra -lm компилирует все реализации паттернов в одно приложение, демонстрирующее их работу.

## Как собрать и запустить

```bash
make clean
clang *.c -o app -Wall -Wextra -lm
./app

