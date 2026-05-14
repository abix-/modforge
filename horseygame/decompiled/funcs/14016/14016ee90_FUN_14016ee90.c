// Address: 0x14016ee90
// Ghidra name: FUN_14016ee90
// ============ 0x14016ee90 FUN_14016ee90 (size=172) ============


undefined8 FUN_14016ee90(longlong param_1)



{

  uint *puVar1;

  char cVar2;

  longlong lVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,1);

      if (cVar2 == '\0') goto LAB_14016ef28;

    }

    if (*(char *)(param_1 + 0x108) == '\0') {

      if (*(longlong *)(param_1 + 0x100) != 0) {

        puVar1 = (uint *)(*(longlong *)(param_1 + 0x100) + 0x30);

        *puVar1 = *puVar1 & 0xfffffffe;

        FUN_140146010(*(undefined8 *)(param_1 + 0x100));

        *(undefined8 *)(param_1 + 0x100) = 0;

      }

      lVar3 = FUN_14016a780(param_1);

      *(longlong *)(param_1 + 0x100) = lVar3;

      if (lVar3 != 0) {

        *(undefined1 *)(param_1 + 0x108) = 1;

        *(uint *)(lVar3 + 0x30) = *(uint *)(lVar3 + 0x30) | 1;

      }

    }

    return *(undefined8 *)(param_1 + 0x100);

  }

LAB_14016ef28:

  FUN_14012e850("Invalid window");

  return 0;

}




