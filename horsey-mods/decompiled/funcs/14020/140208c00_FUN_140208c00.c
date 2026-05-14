// Address: 0x140208c00
// Ghidra name: FUN_140208c00
// ============ 0x140208c00 FUN_140208c00 (size=216) ============


ulonglong FUN_140208c00(undefined8 param_1,ushort param_2,undefined2 param_3,int param_4,int param_5

                       ,int param_6,int param_7)



{

  uint *puVar1;

  ulonglong uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  

  uVar4 = 0;

  uVar5 = 1;

  if (((param_5 == 0xff) && (param_6 == 0x5d)) && ((param_7 - 1U & 0xffffff7f) == 0)) {

    uVar3 = 0;

    puVar1 = &DAT_14034fa20;

    do {

      if ((uint)param_2 == *puVar1) {

        uVar5 = 2;

        break;

      }

      uVar3 = uVar3 + 1;

      puVar1 = puVar1 + 1;

    } while (uVar3 < 0x1b);

  }

  if (((param_4 == 0) && (param_5 == 0xff)) && ((param_6 == 0x47 && (param_7 == 0xd0)))) {

    puVar1 = &DAT_14034fa90;

    do {

      if ((uint)param_2 == *puVar1) {

        return 3;

      }

      uVar4 = uVar4 + 1;

      puVar1 = puVar1 + 1;

    } while (uVar4 < 0x12);

  }

  if (uVar5 != 1) {

    return (ulonglong)uVar5;

  }

  uVar2 = FUN_140157b80(param_2,param_3,param_1,0);

  return uVar2;

}




