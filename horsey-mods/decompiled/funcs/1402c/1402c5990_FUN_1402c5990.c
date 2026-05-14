// Address: 0x1402c5990
// Ghidra name: FUN_1402c5990
// ============ 0x1402c5990 FUN_1402c5990 (size=207) ============


undefined8 FUN_1402c5990(longlong param_1,int param_2,int param_3,int param_4,uint *param_5)



{

  uint uVar1;

  int iVar2;

  undefined8 uVar3;

  uint uVar4;

  int iVar5;

  

  uVar4 = param_3 >> 0x1f & 7;

  uVar1 = param_3 + uVar4;

  iVar2 = (uVar1 & 7) - uVar4;

  iVar5 = (int)uVar1 >> 3;

  if (param_2 <= iVar5) {

    *param_5 = 0;

    uVar3 = FUN_14012e850("Out of bounds reading report data");

    return uVar3;

  }

  uVar1 = FUN_1402c5880(iVar5 + param_1,(int)((param_4 + 7 >> 0x1f & 7U) + param_4 + 7) >> 3);

  *param_5 = uVar1;

  if (0 < iVar2) {

    uVar1 = uVar1 >> ((byte)iVar2 & 0x1f);

    *param_5 = uVar1;

  }

  if (param_4 == 1) {

    *param_5 = uVar1 & 1;

  }

  else {

    if (param_4 == 4) {

      *param_5 = uVar1 & 0xf;

      return 1;

    }

    if (param_4 == 10) {

      *param_5 = uVar1 & 0x3ff;

      return 1;

    }

    if (param_4 == 0xf) {

      *param_5 = uVar1 & 0x7fff;

      return 1;

    }

  }

  return 1;

}




