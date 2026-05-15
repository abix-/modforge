// Address: 0x140272770
// Ghidra name: FUN_140272770
// ============ 0x140272770 FUN_140272770 (size=135) ============


void FUN_140272770(longlong param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)



{

  longlong lVar1;

  undefined1 uVar3;

  undefined2 uVar2;

  undefined1 uVar4;

  

  uVar3 = (undefined1)((ushort)param_3 >> 8);

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(char *)(lVar1 + 0x14) == '\0') {

    FUN_14012e850("That operation is not supported");

    return;

  }

  uVar4 = uVar3;

  if ((*(char *)(lVar1 + 0x6e) == '\0') && (*(char *)(lVar1 + 0x6f) == '\0')) {

    uVar2 = CONCAT11(uVar3,1);

    FUN_140274300(lVar1,1,uVar2);

    uVar4 = (undefined1)((ushort)uVar2 >> 8);

  }

  *(undefined1 *)(lVar1 + 0x6e) = uVar3;

  *(char *)(lVar1 + 0x6f) = (char)((ushort)param_4 >> 8);

  FUN_140274300(lVar1,2,CONCAT11(uVar4,1));

  return;

}




