
## Simple uart example for STM8

USE "sigrok-cli --time -1s -d fx2lafw --channels D0=RX --config samplerate=8m -P uart:baudrate=9600 -B uart=rx"
to see the printfs

Using STM8S103F3.h from https://github.com/gicking/STM8_headers
(and based on an example given by that same repo)
