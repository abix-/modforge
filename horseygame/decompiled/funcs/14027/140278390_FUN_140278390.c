// Address: 0x140278390
// Ghidra name: FUN_140278390
// ============ 0x140278390 FUN_140278390 (size=76) ============


undefined1 FUN_140278390(longlong param_1,undefined8 param_2,char param_3)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (param_3 != *(char *)(lVar1 + 0x2b)) {

    *(char *)(lVar1 + 0x2b) = param_3;

    if (*(char *)(lVar1 + 0x29) != '\0') {

      if (param_3 != '\0') {

        FUN_140278570();

        FUN_140279cd0(lVar1);

        return 1;

      }

      FUN_140278600(lVar1);

    }

    FUN_140279cd0(lVar1);

  }

  return 1;

}




