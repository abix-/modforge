// Address: 0x140284c40
// Ghidra name: FUN_140284c40
// ============ 0x140284c40 FUN_140284c40 (size=160) ============


undefined1

FUN_140284c40(longlong param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,

             undefined1 param_5)



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

      cVar2 = (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x70))

                        (lVar1,param_2,param_3,param_4,param_5);

      lVar4 = lVar4 + 8;

      if (cVar2 != '\0') {

        uVar3 = 1;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0xa8));

  }

  return uVar3;

}




