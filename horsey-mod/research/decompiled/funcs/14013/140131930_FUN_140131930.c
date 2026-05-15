// Address: 0x140131930
// Ghidra name: FUN_140131930
// ============ 0x140131930 FUN_140131930 (size=170) ============


ulonglong FUN_140131930(longlong param_1,undefined8 *param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  byte bVar4;

  ulonglong uVar5;

  

  if (param_1 == 0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","camera");

    return uVar5;

  }

  if (param_2 == (undefined8 *)0x0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14031769c);

    return uVar5;

  }

  FUN_140130b40();

  if (*(int *)(param_1 + 0x1cc) < 1) {

    *param_2 = 0;

    param_2[1] = 0;

    param_2[2] = 0;

    bVar4 = FUN_14012e850("Camera permission has not been granted");

  }

  else {

    uVar1 = *(undefined4 *)(param_1 + 0x58);

    uVar2 = *(undefined4 *)(param_1 + 0x5c);

    uVar3 = *(undefined4 *)(param_1 + 0x60);

    *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 0x54);

    *(undefined4 *)((longlong)param_2 + 4) = uVar1;

    *(undefined4 *)(param_2 + 1) = uVar2;

    *(undefined4 *)((longlong)param_2 + 0xc) = uVar3;

    param_2[2] = *(undefined8 *)(param_1 + 100);

    bVar4 = 1;

  }

  FUN_140130b70(param_1);

  return (ulonglong)bVar4;

}




