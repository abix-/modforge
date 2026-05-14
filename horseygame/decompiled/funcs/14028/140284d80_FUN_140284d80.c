// Address: 0x140284d80
// Ghidra name: FUN_140284d80
// ============ 0x140284d80 FUN_140284d80 (size=118) ============


undefined1 FUN_140284d80(longlong param_1)



{

  undefined1 uVar1;

  undefined1 uVar2;

  char cVar3;

  int iVar4;

  longlong lVar5;

  

  iVar4 = 0;

  uVar1 = 1;

  if (0 < *(int *)(param_1 + 0xa8)) {

    lVar5 = 0;

    uVar2 = uVar1;

    do {

      cVar3 = (**(code **)(*(longlong *)

                            (*(longlong *)(lVar5 + *(longlong *)(param_1 + 0xb0)) + 0x68) + 0x48))()

      ;

      lVar5 = lVar5 + 8;

      uVar1 = 0;

      if (cVar3 != '\0') {

        uVar1 = uVar2;

      }

      iVar4 = iVar4 + 1;

      uVar2 = uVar1;

    } while (iVar4 < *(int *)(param_1 + 0xa8));

  }

  return uVar1;

}




