
SDCC=sdcc -lstm8 -mstm8 --out-fmt-ihx --std-sdcc11


load: main.ihx
	sudo stm8flash -c stlinkv2 -p stm8s003f3 -w main.ihx

main.ihx: main.c print.rel uart.rel
	${SDCC} main.c print.rel uart.rel

print.rel: uart.rel
	${SDCC} -c print.c uart.rel

uart.rel:
	${SDCC} -c uart.c


clean:
	rm *.rel *.ihx *.rst *.map *.lk *.sym *.asm *.lst 2> /dev/null
