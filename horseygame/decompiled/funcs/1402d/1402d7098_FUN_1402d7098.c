// Address: 0x1402d7098
// Ghidra name: FUN_1402d7098
// ============ 0x1402d7098 FUN_1402d7098 (size=210) ============


undefined8 FUN_1402d7098(longlong param_1)



{

  undefined2 *puVar1;

  undefined1 *puVar2;

  int iVar3;

  longlong lVar4;

  undefined1 *puVar5;

  ulonglong uVar6;

  

  iVar3 = *(int *)(param_1 + 0x34);

  if ((iVar3 == 2) ||

     (((iVar3 != 3 && (iVar3 != 0xc)) &&

      ((*(int *)(param_1 + 0x34) == 0xd || ((*(char *)(param_1 + 0x39) + 0x9dU & 0xef) == 0)))))) {

    puVar2 = *(undefined1 **)(param_1 + 0x18);

    puVar5 = *(undefined1 **)(param_1 + 0x458);

    if (*(undefined1 **)(param_1 + 0x458) == (undefined1 *)0x0) {

      puVar5 = (undefined1 *)(param_1 + 0x50);

    }

    *(undefined1 **)(param_1 + 0x18) = puVar2 + 8;

    *puVar5 = *puVar2;

    *(undefined4 *)(param_1 + 0x48) = 1;

  }

  else {

    puVar1 = *(undefined2 **)(param_1 + 0x18);

    *(undefined2 **)(param_1 + 0x18) = puVar1 + 4;

    lVar4 = *(longlong *)(param_1 + 0x458);

    if (lVar4 == 0) {

      lVar4 = param_1 + 0x50;

      uVar6 = 0x200;

    }

    else {

      uVar6 = *(ulonglong *)(param_1 + 0x450) >> 1;

    }

    iVar3 = FUN_1402efd94(param_1 + 0x48,lVar4,uVar6,*puVar1,*(undefined8 *)(param_1 + 8));

    if (iVar3 != 0) {

      *(undefined1 *)(param_1 + 0x38) = 1;

    }

  }

  lVar4 = *(longlong *)(param_1 + 0x458);

  if (*(longlong *)(param_1 + 0x458) == 0) {

    lVar4 = param_1 + 0x50;

  }

  *(longlong *)(param_1 + 0x40) = lVar4;

  return 1;

}




