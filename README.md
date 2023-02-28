# STC15F2K60S2 Bad Apple Video Player (no sound)

Hacking STC C51 8x16 Led Game Kit

I programmed the chip to play video of Bad Apple.

See it in action : https://www.youtube.com/watch?v=RJYBufCqdjc

This game kit is very affordable and some of them comes with STC15F2K60S2.

Features of the chip: 
* 60K Flash Memory
* 2K SRAM
* 2 Timers
* Hardware SPI

For this project I used a Nokia monochrome LCD display with 128x64 pixels.

Frames are stored in 'badAppleLow.bin' as binary file.
Since the chip's memory isn't enough for a 1.5MB video file, I sent the data from a serial connection in the background.

## Screenshot:
![Video view](https://raw.githubusercontent.com/seyfi-hobbies/STC-C51-BadApple/main/images/gameBoard.PNG)
