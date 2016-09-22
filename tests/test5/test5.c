#include <stdio.h>
int main()
{
static double var[29] = {0};
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
"# --[ list := _id5 Assign _id5 ]-- \n\t"
"movq 8(%%r15), %%rax\n\t"
"movq %%rax, 0(%%r15)\n\t"
"# --[ itemCount := _id22 Assign _id22 ]-- \n\t"
"movq 24(%%r15), %%rax\n\t"
"movq %%rax, 16(%%r15)\n\t"
"jmp lbl1\n\t"

"\nlbl1:\n\t"
"# --[ _id91 := hasChanged EqualEqual _id90 ]-- \n\t"
"movq 40(%%r15), %%rax\n\t"
"movq 48(%%r15), %%rbx\n\t"
"cmpq %%rbx, %%rax\n\t"
"jne lbl6\n\t"
"movq %%rax, 32(%%r15)\n\t"
"# --[ hasChanged := _id28 Assign _id28 ]-- \n\t"
"movq 56(%%r15), %%rax\n\t"
"movq %%rax, 40(%%r15)\n\t"
"# --[ _id35 := itemCount Subtraction 1 ]-- \n\t"
"movq 16(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"subq %%rbx, %%rax\n\t"
"movq %%rax, 64(%%r15)\n\t"
"# --[ itemCount := _id35 Assign _id35 ]-- \n\t"
"movq 64(%%r15), %%rax\n\t"
"movq %%rax, 16(%%r15)\n\t"
"# --[ i := 1 Assign 1 ]-- \n\t"
"movq $1, %%rax\n\t"
"movq %%rax, 80(%%r15)\n\t"
"jmp lbl2\n\t"

"\nlbl2:\n\t"
"# --[ _id80 := i LessOrEqual itemCount ]-- \n\t"
"movq 80(%%r15), %%rax\n\t"
"movq 16(%%r15), %%rbx\n\t"
"cmpq %%rbx, %%rax\n\t"
"jg lbl5\n\t"
"movq %%rax, 88(%%r15)\n\t"
"jmp lbl3\n\t"

"\nlbl3:\n\t"
"# --[ _id46 := i Addition 1 ]-- \n\t"
"movq 80(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 96(%%r15)\n\t"
"# --[ _id48 := _id42 GreaterThan _id47 ]-- \n\t"
"movq 112(%%r15), %%rax\n\t"
"movq 120(%%r15), %%rbx\n\t"
"cmpq %%rbx, %%rax\n\t"
"jle lbl4\n\t"
"movq %%rax, 104(%%r15)\n\t"
"# --[ _id57 := i Addition 1 ]-- \n\t"
"movq 80(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 128(%%r15)\n\t"
"# --[ _id63 := i Addition 1 ]-- \n\t"
"movq 80(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 136(%%r15)\n\t"
"# --[ _id53 := _id59 Assign _id59 ]-- \n\t"
"movq 152(%%r15), %%rax\n\t"
"movq %%rax, 144(%%r15)\n\t"
"# --[ hasChanged := _id72 Assign _id72 ]-- \n\t"
"movq 160(%%r15), %%rax\n\t"
"movq %%rax, 40(%%r15)\n\t"
"jmp lbl4\n\t"

"\nlbl4:\n\t"
"# --[ _id84 := i Addition 1 ]-- \n\t"
"movq 80(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 168(%%r15)\n\t"
"# --[ i := _id84 Assign _id84 ]-- \n\t"
"movq 168(%%r15), %%rax\n\t"
"movq %%rax, 80(%%r15)\n\t"
"jmp lbl2\n\t"

"\nlbl5:\n\t"
"jmp lbl1\n\t"

"\nlbl6:\n\t"
"# --[ i := 1 Assign 1 ]-- \n\t"
"movq $1, %%rax\n\t"
"movq %%rax, 80(%%r15)\n\t"
"jmp lbl7\n\t"

"\nlbl7:\n\t"
"# --[ _id106 := i LessOrEqual itemCount ]-- \n\t"
"movq 80(%%r15), %%rax\n\t"
"movq 16(%%r15), %%rbx\n\t"
"cmpq %%rbx, %%rax\n\t"
"jg lbl8\n\t"
"movq %%rax, 176(%%r15)\n\t"
"# --[ NS := FCH FuncCallHead FCH ]-- \n\t"
"pushq %%rax\n\t"
"pushq %%rbx\n\t"
"# --[ _id102 := print FuncCall _id101 ]-- \n\t"
"movq 208(%%r15), %%rbx\n\t"
"leaq %[printInt], %%rdi\n\t"
"movq %%rbx, %%rsi\n\t"
"movq $0, %%rax\n\t"
"call printf\n\t"
"movq %%rax, 192(%%r15)\n\t"
"# --[ NS := FCF FuncCallFoot FCF ]-- \n\t"
"popq %%rbx\n\t"
"popq %%rax\n\t"
"# --[ _id110 := i Addition 1 ]-- \n\t"
"movq 80(%%r15), %%rax\n\t"
"movq $1, %%rbx\n\t"
"addq %%rbx, %%rax\n\t"
"movq %%rax, 224(%%r15)\n\t"
"# --[ i := _id110 Assign _id110 ]-- \n\t"
"movq 224(%%r15), %%rax\n\t"
"movq %%rax, 80(%%r15)\n\t"
"jmp lbl7\n\t"

"\nlbl8:\n\t"
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
