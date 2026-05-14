// Address: 0x14018c3a0
// Ghidra name: FUN_14018c3a0
// ============ 0x14018c3a0 FUN_14018c3a0 (size=175) ============


void FUN_14018c3a0(undefined8 param_1,char param_2,uint param_3,char param_4,undefined8 *param_5,

                  byte param_6,undefined4 param_7)



{

  uint uVar1;

  uint uVar2;

  undefined1 uVar3;

  

  if (param_4 == '\0') {

    uVar1 = (uint)param_6;

  }

  else if (param_6 == 1) {

    uVar1 = 3;

  }

  else {

    uVar1 = (uint)param_6;

    if (param_6 == 3) {

      uVar1 = 1;

    }

  }

  uVar2 = 1 << ((byte)(uVar1 - 1) & 0x1f);

  if ((*(byte *)((longlong)param_5 + 0x66) & uVar2) == 0) {

    uVar2 = uVar2 & param_3;

    if (param_2 == '\0') {

      if (uVar2 == 0) {

        return;

      }

      uVar3 = 0;

    }

    else {

      if (uVar2 != 0) {

        return;

      }

      uVar3 = 1;

    }

    FUN_1401628d0(param_1,*param_5,param_7,uVar1,uVar3);

  }

  else if (param_2 == '\0') {

    *(byte *)((longlong)param_5 + 0x66) =

         *(byte *)((longlong)param_5 + 0x66) & ~(byte)(1 << (uVar1 - 1 & 0x1f));

    FUN_14022c8c0(*param_5);

    return;

  }

  return;

}




