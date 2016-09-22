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
"# --[ _id6 := 22 Subtraction 11 ]-- \n\t"
"movq $22, %%rax\n\t"
"movq $11, %%rbx\n\t"
"subq %%rbx, %%rax\n\t"
"movq %%rax, 0(%%r15)\n\t"
"# --[ _id8 := _id6 Division 1 ]-- \n\t"
"movq 0(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"movq $0, %%rdx\n\t"
"divq %%rbx\n\t"
"movq %%rax, 24(%%r15)\n\t"
"# --[ _id10 := _id8 Multiplication 44 ]-- \n\t"
"movq 24(%%r15), %%rax\n\t"
"movq $44, %%rbx\n\t"
"mulq %%rbx\n\t"
"movq %%rax, 40(%%r15)\n\t"
"# --[ _id11 := 13 Addition _id10 ]-- \n\t"
"movq $13, %%rax\n\t"
"movq 40(%%r15), %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 56(%%r15)\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id12 := print FuncCall _id11 ]-- \n\t"
"movq 56(%%r15), %%rbx\n\t"
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
