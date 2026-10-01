all: compile

compile:
	pio run

upload:
	pio run --target upload

clean:
	pio run --target clean

monitor:
	pio device monitor

# Comando para subir el código y abrir el monitor serie inmediatamente
flash:
	pio run --target upload && pio device monitor
