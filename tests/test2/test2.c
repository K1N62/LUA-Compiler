#include <stdio.h>
int main()
{
static double var[13] = {0};
static double intbuf[1]   = {0};
static char   str[]       = "";
static char   printInt[]  = "%d\n";
static char   printStr[]  = "%s\n";
static char   writeInt[]  = "%d";
static char   writeStr[]  = "%s";
static char   readInt[]   = "%d";
asm(
"leaq %[var], %% r15\n\t"
"leaq %[str], %% r14\n\t"
"jmp lbl0\n\t"

"\nlbl0:\n\t"
"# --[ x := 7 Assign 7 ]-- \n\t"
"movq $7, %%rax\n\t"
"movq %%rax, 0(%%r15)\n\t"
"# --[ _id11 := 10 Addition x ]-- \n\t"
"movq $10, %%rax\n\t"
"movq 0(%%r15), %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 16(%%r15)\n\t"
"# --[ _id13 := _id11 Multiplication 2 ]-- \n\t"
"movq 16(%%r15), %%rax\n\t"
"movq $2, %%rbx\n\t"
"mulq %%rbx\n\t"
"movq %%rax, 32(%%r15)\n\t"
"# --[ y := _id13 Assign _id13 ]-- \n\t"
"movq 32(%%r15), %%rax\n\t"
"movq %%rax, 48(%%r15)\n\t"
"# --[ _id20 := y Subtraction x ]-- \n\t"
"movq 48(%%r15), %%rax\n\t"
"movq 0(%%r15), %%rbx\n\t"
"subq %%rbx, %%rax\n\t"
"movq %%rax, 56(%%r15)\n\t"
"# --[ z := _id20 Assign _id20 ]-- \n\t"
"movq 56(%%r15), %%rax\n\t"
"movq %%rax, 64(%%r15)\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id25 := print FuncCall z ]-- \n\t"
"movq 64(%%r15), %%rbx\n\t"
"leaq %[printInt], %%rdi\n\t"
"movq %%rbx, %%rsi\n\t"
"movq $0, %%rax\n\t"
"call printf\n\t"
"movq %%rax, 80(%%r15)\n\t"
"# --[ NS := FCF FuncCallFoot FCF ]-- \n\t"
"popq %%rbx\n\t"
"popq %%rax\n\t"
: [var]      "+g" (var),
  [intbuf]   "+g" (intbuf),
  [str]      "+g" (str),
  [printInt] "+g" (printInt),
  [printStr] "+g" (printStr),
  [writeInt] "+g" (writeInt),
  [writeStr] "+g" (writeStr),
  [readInt]  "+g" (readInt)
:
: "rax",
  "rbx",
  "rcx",
  "rdx",
  "rdi",
  "rsi",
  "al",
  "bl",
  "r15",
  "r14"
);
}
