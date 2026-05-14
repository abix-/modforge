// Address: 0x140174130
// Ghidra name: FUN_140174130
// ============ 0x140174130 FUN_140174130 (size=159) ============


ulonglong FUN_140174130(char *param_1)



{

  byte bVar1;

  int iVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar3 = FUN_1401730c0();

    return uVar3;

  }

  if (*(int *)(DAT_1403fc410 + 0x570) == 0) {

    if (*(code **)(DAT_1403fc410 + 0x1f8) != (code *)0x0) {

      bVar1 = (**(code **)(DAT_1403fc410 + 0x1f8))(DAT_1403fc410,param_1);

      if (bVar1 != 0) {

        *(int *)(DAT_1403fc410 + 0x570) = *(int *)(DAT_1403fc410 + 0x570) + 1;

      }

      return (ulonglong)bVar1;

    }

    uVar3 = FUN_14016ba20("Vulkan");

    return uVar3;

  }

  if ((param_1 != (char *)0x0) &&

     (iVar2 = strcmp(param_1,(char *)(DAT_1403fc410 + 0x574)), iVar2 != 0)) {

    uVar3 = FUN_14012e850("Vulkan loader library already loaded");

    return uVar3;

  }

  *(int *)(DAT_1403fc410 + 0x570) = *(int *)(DAT_1403fc410 + 0x570) + 1;

  return 1;

}




