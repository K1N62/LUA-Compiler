#include <stdio.h>
int main()
{
static double var[22] = {0};
static double intbuf[1]   = {0};
static char   str[]       = "enter a number:\0*number\0 is a factor of \0";
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
"# --[ _id3 := _id3 String _id3 ]-- \n\t"
"leaq 0(%%r14), %%rax\n\t"
"movq %%rax, 0(%%r15)\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id4 := print FuncCall _id3 ]-- \n\t"
"movq 0(%%r15), %%rbx\n\t"
"leaq %[printStr], %%rdi\n\t"
"movq %%rbx, %%rsi\n\t"
"movq $0, %%rax\n\t"
"call printf\n\t"
"movq %%rax, 16(%%r15)\n\t"
"# --[ NS := FCF FuncCallFoot FCF ]-- \n\t"
"popq %%rbx\n\t"
"popq %%rax\n\t"
"# --[ _id11 := _id11 String _id11 ]-- \n\t"
"leaq 16(%%r14), %%rax\n\t"
"movq %%rax, 40(%%r15)\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id12 := read FuncCall _id11 ]-- \n\t"
"leaq %[readInt], %%rdi\n\t"
"leaq %[intbuf], %%rsi\n\t"
"movq $0, %%rax\n\t"
"call scanf\n\t"
"movq %[intbuf], %%rax\n\t"
"movq %%rax, 48(%%r15)\n\t"
"# --[ NS := FCF FuncCallFoot FCF ]-- \n\t"
"popq %%rbx\n\t"
"popq %%rax\n\t"
"# --[ n := _id12 Assign _id12 ]-- \n\t"
"movq 48(%%r15), %%rax\n\t"
"movq %%rax, 64(%%r15)\n\t"
"# --[ i := 2 Assign 2 ]-- \n\t"
"movq $2, %%rax\n\t"
"movq %%rax, 72(%%r15)\n\t"
"jmp lbl1\n\t"

"\nlbl1:\n\t"
"# --[ _id43 := i LessOrEqual n ]-- \n\t"
"movq 72(%%r15), %%rax\n\t"
"movq 64(%%r15), %%rbx\n\t"
"cmpq %%rbx, %%rax\n\t"
"jg lbl4\n\t"
"movq %%rax, 88(%%r15)\n\t"
"jmp lbl2\n\t"

"\nlbl2:\n\t"
"# --[ _id19 := n Modulo i ]-- \n\t"
"movq 64(%%r15), %%rax\n\t"
"movq 72(%%r15), %%rbx\n\t"
"movq $0, %%rdx\n\t"
"divq %%rbx\n\t"
"movq %%rdx, %%rax\n\t"
"movq %%rax, 96(%%r15)\n\t"
"# --[ _id21 := _id19 EqualEqual 0 ]-- \n\t"
"movq 96(%%r15), %%rax\n\t"
"movq $0, %%rbx\n\t"
"cmpq %%rbx, %%rax\n\t"
"jne lbl3\n\t"
"movq %%rax, 104(%%r15)\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id27 := write FuncCall i ]-- \n\t"
"movq 72(%%r15), %%rbx\n\t"
"leaq %[writeInt], %%rdi\n\t"
"movq %%rbx, %%rsi\n\t"
"movq $0, %%rax\n\t"
"call printf\n\t"
"movq %%rax, 120(%%r15)\n\t"
"# --[ NS := FCF FuncCallFoot FCF ]-- \n\t"
"popq %%rbx\n\t"
"popq %%rax\n\t"
"# --[ _id31 := _id31 String _id31 ]-- \n\t"
"leaq 24(%%r14), %%rax\n\t"
"movq %%rax, 136(%%r15)\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id32 := write FuncCall _id31 ]-- \n\t"
"movq 136(%%r15), %%rbx\n\t"
"leaq %[writeStr], %%rdi\n\t"
"movq %%rbx, %%rsi\n\t"
"movq $0, %%rax\n\t"
"call printf\n\t"
"movq %%rax, 144(%%r15)\n\t"
"# --[ NS := FCF FuncCallFoot FCF ]-- \n\t"
"popq %%rbx\n\t"
"popq %%rax\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id36 := print FuncCall n ]-- \n\t"
"movq 64(%%r15), %%rbx\n\t"
"leaq %[printInt], %%rdi\n\t"
"movq %%rbx, %%rsi\n\t"
"movq $0, %%rax\n\t"
"call printf\n\t"
"movq %%rax, 152(%%r15)\n\t"
"# --[ NS := FCF FuncCallFoot FCF ]-- \n\t"
"popq %%rbx\n\t"
"popq %%rax\n\t"
"jmp lbl3\n\t"

"\nlbl3:\n\t"
"# --[ _id47 := i Addition 1 ]-- \n\t"
"movq 72(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 160(%%r15)\n\t"
"# --[ i := _id47 Assign _id47 ]-- \n\t"
"movq 160(%%r15), %%rax\n\t"
"movq %%rax, 72(%%r15)\n\t"
"jmp lbl1\n\t"

"\nlbl4:\n\t"
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
