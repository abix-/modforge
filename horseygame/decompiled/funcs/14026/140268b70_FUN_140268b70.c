// Address: 0x140268b70
// Ghidra name: FUN_140268b70
// ============ 0x140268b70 FUN_140268b70 (size=193) ============


undefined1 FUN_140268b70(longlong param_1,undefined8 param_2,byte *param_3,int param_4)



{

  byte bVar1;

  longlong lVar2;

  undefined1 uVar3;

  char cVar4;

  ulonglong uVar5;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  if (param_4 == 10) {

    if (*param_3 != 0x10) {

      uVar3 = FUN_14012e850("Unknown Nintendo Switch Pro effect type");

      return uVar3;

    }

    *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_3 + 2);

    *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(param_3 + 6);

    cVar4 = FUN_14026d560(lVar2);

    if (cVar4 == '\0') {

      return false;

    }

    *(undefined2 *)(lVar2 + 0x90) = 0;

  }

  else {

    if (0xfe < param_4 - 2U) {

      uVar3 = FUN_14012e850("That operation is not supported");

      return uVar3;

    }

    bVar1 = *param_3;

    uVar5 = (ulonglong)bVar1;

    if (bVar1 == 3) {

      cVar4 = *(char *)(param_1 + 0x54);

    }

    else {

      if (bVar1 != 0x38) goto LAB_140268bfa;

      cVar4 = FUN_14026bf00(lVar2);

    }

    if (cVar4 != '\0') {

LAB_140268bfa:

      cVar4 = FUN_14026d5b0(lVar2,uVar5 & 0xffffffff,param_3 + 1,(char)param_4 + -1,0);

      return cVar4 != '\0';

    }

  }

  return true;

}




