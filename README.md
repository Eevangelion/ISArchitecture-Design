# Description
Над проектом работают: Березикова Александра, Ботвиньева Екатерина, Платонов Иван. 

Архитектурная документация находится в файле [roguelike-system-design-2hw.pdf](roguelike-system-design-2hw.pdf).

Данный проект реализует простую терминальную rogue-like игру.

# Getting started

Чтобы воспользоваться приложением, необходимо склонить репозиторий в локальную директорию и перейти на ветку, связанную с интерпретатором.

```bash
git clone https://github.com/Eevangelion/ISArchitecture-Design.git 
cd ISArchitecture-Design
git switch hw3-roguelike
```

После чего собрать (см. Build раздел) и запустить (см. Launch раздел) приложение. 

# Build

```bash
cd roguelike-game
./gradlew
```

# Testing

```bash
cd roguelike-game
./gradlew test
```

# Launch

```bash
cd roguelike-game
./gradlew run
```
# Troubleshooting

Если есть проблемы с запуском или компиляцией из-за несовместимости версий Java и Gradle, необходимо установить OpenJDK 11 и выполнить следующую команду:
```bash
cd roguelike-game
./gradlew compileJava
```