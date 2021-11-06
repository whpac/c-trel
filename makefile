C_SOURCES = $(wildcard src/*.c) $(wildcard src/**/*.c) $(wildcard src/**/**/*.c)
HEADERS = $(wildcard src/*.h) $(wildcard src/**/*.h) $(wildcard src/**/**/*.h)
OBJ = ${patsubst src/%.c,obj/%.o,$(C_SOURCES)}
OUTPUT = bin/c-trel

all: folders ${OUTPUT}
run: all
	./${OUTPUT}

run-text: all
	./${OUTPUT} text

${OUTPUT}: ${OBJ}
	gcc -o $@ $^

obj/%.o: src/%.c ${HEADERS}
	gcc -c $< -o $@

clean:
	rm -rf obj

# Ignores errors when bin and obj directories exist
# 2> NUL causes the error message to disappear forever in /dev/null
# || (exit 0) fools the shell that the command was successful
folders:
	mkdir obj 2> /dev/null || (exit 0)
	mkdir bin 2> /dev/null || (exit 0)
	cd src && find . -type d -exec mkdir -p -- ../obj/{} \;