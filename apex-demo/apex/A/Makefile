APEX=/homes/cs240/2018Spring/lab-apex/apex-bin/
CFLAGS=-g -O0 -Wall -Werror=implicit-function-declaration -fno-builtin -std=c99 -Wno-unused-variable -Wno-unused-value -DNDEBUG -include ${APEX}/instrument/common.h
LLVM=${APEX}/llvm
CLANG=${LLVM}/bin/clang-3.7
OPT=${LLVM}/bin/opt -load ${LLVM}/lib/LLVMHello.so
LLC=${LLVM}/bin/llc
LLVM_LINK=${LLVM}/bin/llvm-link
LD=${CLANG}
CC=${CLANG}

SOURCES=src.c
BITCODES=$(SOURCES:%.c=%.bc)

.PHONY: all clean run build

all: build run
run: symb.out 
build: input exec cfg.out  
clean:
	rm -f exec exec.org exec.asm src.o exec.*.[so] *.bc *.out dot.[0123] cfg.out cfg.x stdout *.log symb.out.xxx

exec: exec.3.o ${APEX}/instrument/instrument.o
	${LD} -o $@ $^
exec.1.bc: $(BITCODES)
	${LLVM_LINK} -o $@ $^
%.bc: %.c
	${CLANG} -c -emit-llvm ${CFLAGS} $< -o $@
%.2.bc: %.1.bc
	${OPT} -constantexpr $< -o $@
%.3.bc: %.2.bc
	${OPT} -mystuff $< -o $@
%.s: %.bc
	${LLC} -O0 $< -o $@
%.o: %.s
	${CC} -c $<


cfg.out:
	PYTHONPATH=${APEX}/lib ${APEX}/apex/llvm_cfg.py

exec.out: exec
	# -./exec < ../../input > stdout
	-./exec > stdout

symb.out: exec exec.out cfg.out
	PYTHONPATH=${APEX}/lib ${APEX}/apex/symbexec.py -out symb.out -cfg cfg.out -llvm llvm.out -exec exec.out -args args.out

input: ../input
	ln -fs $< $@


${APEX}/instrument/instrument.o: ${APEX}/instrument/instrument.c
	${CC} -g -O0 -std=c99 -c -o $@ $<

.DELETE_ON_ERROR:
