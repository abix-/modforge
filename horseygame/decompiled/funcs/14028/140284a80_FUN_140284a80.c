// Address: 0x140284a80
// Ghidra name: FUN_140284a80
// ============ 0x140284a80 FUN_140284a80 (size=151) ============


undefined1 FUN_140284a80(longlong param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)



{

  longlong lVar1;

  char cVar2;

  undefined1 uVar3;

  longlong lVar4;

  int iVar5;

  

  uVar3 = 0;

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 0xa8)) {

    lVar4 = 0;

    uVar3 = 0;

    do {

      lVar1 = *(longlong *)(lVar4 + *(longlong *)(param_1 + 0xb0));

      cVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x58))(lVar1,param_2,param_3,param_4);

      lVar4 = lVar4 + 8;

      if (cVar2 != '\0') {

        uVar3 = 1;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0xa8));

  }

  return uVar3;

}




