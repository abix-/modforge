// Address: 0x14021aae0
// Ghidra name: FUN_14021aae0
// ============ 0x14021aae0 FUN_14021aae0 (size=49) ============


longlong FUN_14021aae0(int param_1)



{

  longlong *plVar1;

  longlong lVar2;

  

  if ((param_1 < 0) || (DAT_1403fdb68 <= param_1)) {

    lVar2 = 0;

  }

  else {

    lVar2 = DAT_1403fdb58;

    if (0 < param_1) {

      do {

        plVar1 = (longlong *)(lVar2 + 0x490);

        param_1 = param_1 + -1;

        lVar2 = *plVar1;

      } while (0 < param_1);

      return *plVar1;

    }

  }

  return lVar2;

}




