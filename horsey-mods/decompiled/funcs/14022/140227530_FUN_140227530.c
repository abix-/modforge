// Address: 0x140227530
// Ghidra name: FUN_140227530
// ============ 0x140227530 FUN_140227530 (size=215) ============


undefined8

FUN_140227530(undefined8 *param_1,longlong param_2,int param_3,int param_4,undefined4 param_5,

             undefined4 param_6)



{

  int iVar1;

  uint uVar2;

  undefined1 uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  uVar7 = (ulonglong)param_4;

  uVar5 = (ulonglong)param_3;

  if (*(int *)(param_2 + 0x34) != 0) {

    uVar5 = FUN_140174c40(*(int *)(param_2 + 0x34),"SDL.surface.hotspot.x",uVar5);

    uVar7 = FUN_140174c40(*(undefined4 *)(param_2 + 0x34),"SDL.surface.hotspot.y",uVar7);

  }

  uVar4 = 0;

  uVar6 = uVar4;

  if ((-1 < (int)uVar5) &&

     (uVar2 = *(int *)(param_2 + 8) - 1, uVar6 = uVar5, (int)uVar2 < (int)uVar5)) {

    uVar6 = (ulonglong)uVar2;

  }

  uVar5 = uVar4;

  if ((-1 < (int)uVar7) &&

     (uVar2 = *(uint *)(param_2 + 0xc) - 1, uVar5 = uVar7, (int)uVar2 < (int)uVar7)) {

    uVar5 = (ulonglong)uVar2;

  }

  *param_1 = 0;

  param_1[1] = 0;

  iVar1 = *(int *)(param_2 + 8);

  uVar3 = (undefined1)iVar1;

  if (0xff < iVar1) {

    uVar3 = 0;

  }

  *(undefined1 *)param_1 = uVar3;

  uVar2 = *(uint *)(param_2 + 0xc);

  uVar7 = (ulonglong)(uVar2 & 0xff);

  if (0xff < (int)uVar2) {

    uVar7 = uVar4;

  }

  *(undefined4 *)(param_1 + 1) = param_5;

  *(undefined4 *)((longlong)param_1 + 0xc) = param_6;

  *(short *)((longlong)param_1 + 4) = (short)uVar6;

  *(short *)((longlong)param_1 + 6) = (short)uVar5;

  *(char *)((longlong)param_1 + 1) = (char)uVar7;

  return CONCAT71((uint7)(uint3)((uint)param_6 >> 8),1);

}




