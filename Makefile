
SDCC=sdcc -lstm8 -mstm8 --out-fmt-ihx --std-sdcc11


build: main.ihx

load: main.ihx
	sudo stm8flash -c stlinkv2 -p stm8s003f3 -w main.ihx

monitor: load
	./monitor.sh

main.ihx: main.c print.rel uart.rel hx711.rel *.h
	${SDCC} main.c print.rel uart.rel hx711.rel

print.rel: uart.rel
	${SDCC} -c print.c uart.rel

uart.rel:
	${SDCC} -c uart.c

hx711.rel:
	${SDCC} -c hx711.c



clean:
	rm *.rel *.ihx *.rst *.map *.lk *.sym *.asm *.lst 2> /dev/null
