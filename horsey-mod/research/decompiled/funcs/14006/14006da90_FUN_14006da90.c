// Address: 0x14006da90
// Ghidra name: FUN_14006da90
// ============ 0x14006da90 FUN_14006da90 (size=144) ============


void FUN_14006da90(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  uVar2 = CONCAT71((int7)((ulonglong)param_1 >> 8),-(*(char *)(param_1 + 0x11) != '\0')) &

          0xffffffffffffff10;

  cVar1 = '\x01';

  if (*(char *)(param_1 + 0x10) != '\0') {

    cVar1 = '\t';

  }

  FUN_140075710(CONCAT71((int7)(uVar2 >> 8),(char)uVar2 + cVar1 + *(char *)(param_1 + 0x38)));

  FUN_140075690(*(undefined1 *)(param_1 + 0xc));

  FUN_140075690(*(undefined1 *)(param_1 + 0x48));

  FUN_1400756b0(*(undefined2 *)(param_1 + 0x44));

  FUN_140075670(*(undefined4 *)(param_1 + 0x18));

  FUN_140075670(*(undefined4 *)(param_1 + 0x24));

  FUN_140075790(*(undefined8 *)(param_1 + 0x1c));

  FUN_140075770(*(undefined4 *)(param_1 + 0x28));

  FUN_140075770(*(undefined4 *)(param_1 + 0x2c));

  FUN_140075770(*(undefined4 *)(param_1 + 0x30));

  FUN_140075770(*(undefined4 *)(param_1 + 0x34));

  return;

}




