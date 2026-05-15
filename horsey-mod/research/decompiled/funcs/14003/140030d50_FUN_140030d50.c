// Address: 0x140030d50
// Ghidra name: FUN_140030d50
// ============ 0x140030d50 FUN_140030d50 (size=213) ============


void FUN_140030d50(longlong param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  

  lVar5 = *(longlong *)(param_1 + 0x268);

  iVar3 = 0;

  lVar2 = *(longlong *)(param_1 + 0x260);

  if (lVar5 - lVar2 >> 3 != 0) {

    lVar4 = 0;

    do {

      puVar1 = *(undefined8 **)(lVar4 + lVar2);

      if (puVar1 != (undefined8 *)0x0) {

        (**(code **)*puVar1)(puVar1,1);

      }

      lVar5 = *(longlong *)(param_1 + 0x268);

      iVar3 = iVar3 + 1;

      lVar2 = *(longlong *)(param_1 + 0x260);

      lVar4 = lVar4 + 8;

    } while ((ulonglong)(longlong)iVar3 < (ulonglong)(lVar5 - lVar2 >> 3));

  }

  if (lVar2 != lVar5) {

    *(longlong *)(param_1 + 0x268) = lVar2;

  }

  if (*(longlong *)(param_1 + 0x2a0) != *(longlong *)(param_1 + 0x2a8)) {

    *(longlong *)(param_1 + 0x2a8) = *(longlong *)(param_1 + 0x2a0);

  }

  lVar5 = *(longlong *)(param_1 + 600);

  if (lVar5 != 0) {

    FUN_140005cf0(lVar5);

    FUN_1402c7088(lVar5,0x19380);

    *(undefined8 *)(param_1 + 600) = 0;

  }

  *(undefined4 *)(param_1 + 0x27c) = 0;

  return;

}




