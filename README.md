# arduino-sygnalizacja
# Projekt Sygnalizacji Świetlnej w TinkerCAD (Arduino + millis)

Ten projekt przedstawia prostą, dwustronną sygnalizację świetlną wykonaną w środowisku TinkerCAD Circuits przy użyciu płyty Arduino oraz funkcji `millis()` (programowanie nieblokujące).

## Jak działa układ?

Cykl sygnalizacji składa się z 4 kroków:

1. **Lewa strona ZIELONA**, prawa strona CZERWONA (czas: `4 sekundy`)
2. **Przerwa:** po obu stronach świecą się CZERWONE (czas: `2 sekundy`)
3. **Prawa strona ZIELONA**, lewa strona CZERWONA (czas: `4 sekundy`)
4. **Przerwa:** po obu stronach świecą się CZERWONE (czas: `2 sekundy`) – po czym cykl wraca do punktu 1.

\---

## Podłączenie elementów (Pinout)

Do płytki Arduino Uno podłącz diody przez rezystory ochronne (np. $220,\\Omega$ lub $330,\\Omega$):

* **Lewa dioda zielona:** Pin `2`
* **Lewa dioda czerwona:** Pin `3`
* **Prawa dioda zielona:** Pin `4`
* **Prawa dioda czerwona:** Pin `5`
* **GND:** Wszystkie diody połączone z masą przez rezystory.
