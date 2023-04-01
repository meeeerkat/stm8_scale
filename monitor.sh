#!/bin/sh

sigrok-cli --time -1s -d fx2lafw --channels D0=RX --config samplerate=8m -P uart:baudrate=9600 -B uart=rx
