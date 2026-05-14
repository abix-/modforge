// Address: 0x140289bb0
// Ghidra name: FUN_140289bb0
// ============ 0x140289bb0 FUN_140289bb0 (size=188) ============


undefined8 FUN_140289bb0(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  lVar2 = FUN_140149350();

  uVar3 = FUN_140289c70(param_1);

  iVar1 = (**(code **)(*DAT_1403fde80 + 0x28))(DAT_1403fde80,uVar3,param_2);

  while (iVar1 == -0x7ff8fb70) {

    uVar4 = FUN_140149350();

    if (lVar2 + 8000U <= uVar4) goto LAB_140289c45;

    uVar4 = (lVar2 + 8000U) - uVar4;

    uVar5 = 300;

    if (uVar4 < 300) {

      uVar5 = uVar4 & 0xffffffff;

    }

    FUN_1401492f0(uVar5);

    iVar1 = (**(code **)(*DAT_1403fde80 + 0x28))(DAT_1403fde80,uVar3,param_2);

  }

  if (iVar1 < 0) {

LAB_140289c45:

    uVar3 = FUN_1401a9ef0("WASAPI can\'t find requested audio endpoint",iVar1);

  }

  else {

    uVar3 = 1;

  }

  return uVar3;

}




