// Address: 0x14016c850
// Ghidra name: FUN_14016c850
// ============ 0x14016c850 FUN_14016c850 (size=218) ============


ulonglong FUN_14016c850(char *param_1)



{

  byte bVar1;

  int iVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar3 = FUN_1401730c0();

    return uVar3;

  }

  if (*(int *)(DAT_1403fc410 + 0x410) != 0) {

    if ((param_1 != (char *)0x0) &&

       (iVar2 = strcmp(param_1,(char *)(DAT_1403fc410 + 0x418)), iVar2 != 0)) {

      uVar3 = FUN_14012e850("OpenGL library already loaded");

      return uVar3;

    }

    *(int *)(DAT_1403fc410 + 0x410) = *(int *)(DAT_1403fc410 + 0x410) + 1;

    return 1;

  }

  if (*(code **)(DAT_1403fc410 + 0x1a0) == (code *)0x0) {

    uVar3 = FUN_14016ba20("OpenGL");

    return uVar3;

  }

  bVar1 = (**(code **)(DAT_1403fc410 + 0x1a0))(DAT_1403fc410,param_1);

  if (bVar1 == 0) {

    if (*(code **)(DAT_1403fc410 + 0x1b0) != (code *)0x0) {

      (**(code **)(DAT_1403fc410 + 0x1b0))();

    }

    return 0;

  }

  *(int *)(DAT_1403fc410 + 0x410) = *(int *)(DAT_1403fc410 + 0x410) + 1;

  return (ulonglong)bVar1;

}




