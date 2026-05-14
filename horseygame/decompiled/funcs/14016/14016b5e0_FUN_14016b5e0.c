// Address: 0x14016b5e0
// Ghidra name: FUN_14016b5e0
// ============ 0x14016b5e0 FUN_14016b5e0 (size=179) ============


undefined8 FUN_14016b5e0(longlong param_1)



{

  uint *puVar1;

  char cVar2;

  longlong lVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 != '\0')))) {

    lVar3 = DAT_1403fc410;

    if (*(longlong *)(param_1 + 0x100) != 0) {

      puVar1 = (uint *)(*(longlong *)(param_1 + 0x100) + 0x30);

      *puVar1 = *puVar1 & 0xfffffffe;

      FUN_140146010(*(undefined8 *)(param_1 + 0x100));

      lVar3 = DAT_1403fc410;

      *(undefined8 *)(param_1 + 0x100) = 0;

      *(undefined1 *)(param_1 + 0x108) = 0;

    }

    if (*(char *)(lVar3 + 0x318) != '\0') {

      if (*(code **)(lVar3 + 0x158) != (code *)0x0) {

        (**(code **)(lVar3 + 0x158))(lVar3,param_1);

      }

    }

    return 1;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




