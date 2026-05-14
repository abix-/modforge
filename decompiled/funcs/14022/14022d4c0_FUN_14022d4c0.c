// Address: 0x14022d4c0
// Ghidra name: FUN_14022d4c0
// ============ 0x14022d4c0 FUN_14022d4c0 (size=53) ============


undefined1 FUN_14022d4c0(longlong param_1,int param_2,undefined1 param_3)



{

  longlong lVar1;

  undefined1 uVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  if (param_2 == 0) {

    *(undefined1 *)(lVar1 + 0x12a) = param_3;

  }

  else {

    if (param_2 != 1) {

      return 0;

    }

    *(undefined1 *)(lVar1 + 299) = param_3;

  }

  if (*(longlong *)(lVar1 + 0x138) != 0) {

    return 1;

  }

  uVar2 = FUN_14022d5a0();

  return uVar2;

}




