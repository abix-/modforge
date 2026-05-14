// Address: 0x140147790
// Ghidra name: FUN_140147790
// ============ 0x140147790 FUN_140147790 (size=141) ============


void FUN_140147790(longlong param_1,undefined1 param_2)



{

  char cVar1;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return;

  }

  FUN_140147020(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),

                *(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x40),

                *(undefined4 *)(param_1 + 0x34),*(undefined8 *)(param_1 + 0x18),

                *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 4),

                *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x34),

                *(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10),param_2);

  return;

}




