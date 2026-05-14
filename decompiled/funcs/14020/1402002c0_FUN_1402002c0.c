// Address: 0x1402002c0
// Ghidra name: FUN_1402002c0
// ============ 0x1402002c0 FUN_1402002c0 (size=73) ============


longlong FUN_1402002c0(longlong param_1)



{

  longlong *plVar1;

  longlong lVar2;

  

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  if (*plVar1 == 0) {

    lVar2 = plVar1[1];

    *plVar1 = lVar2;

    if (lVar2 != 0) {

      return lVar2;

    }

    lVar2 = FUN_14016ee90(*(undefined8 *)(param_1 + 0x118));

    if (lVar2 != 0) {

      plVar1[1] = lVar2;

      *plVar1 = lVar2;

    }

  }

  return *plVar1;

}




