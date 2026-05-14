// Address: 0x1402d6ad0
// Ghidra name: FUN_1402d6ad0
// ============ 0x1402d6ad0 FUN_1402d6ad0 (size=124) ============


undefined8 FUN_1402d6ad0(longlong param_1)



{

  ushort uVar1;

  int iVar2;

  undefined8 *puVar3;

  ushort *puVar4;

  ulonglong uVar5;

  bool bVar6;

  

  puVar3 = *(undefined8 **)(param_1 + 0x18);

  *(undefined8 **)(param_1 + 0x18) = puVar3 + 1;

  puVar4 = (ushort *)*puVar3;

  if ((puVar4 == (ushort *)0x0) || (*(longlong *)(puVar4 + 4) == 0)) {

    uVar5 = 6;

    *(char **)(param_1 + 0x40) = "(null)";

  }

  else {

    iVar2 = *(int *)(param_1 + 0x34);

    if (iVar2 == 2) {

LAB_1402d6b1a:

      bVar6 = false;

    }

    else if ((iVar2 == 3) || (iVar2 == 0xc)) {

      bVar6 = true;

    }

    else {

      if (*(int *)(param_1 + 0x34) == 0xd) goto LAB_1402d6b1a;

      bVar6 = (*(char *)(param_1 + 0x39) + 0x9dU & 0xef) != 0;

    }

    *(longlong *)(param_1 + 0x40) = *(longlong *)(puVar4 + 4);

    uVar1 = *puVar4;

    uVar5 = (ulonglong)uVar1;

    if (bVar6) {

      *(undefined1 *)(param_1 + 0x4c) = 1;

      uVar5 = (ulonglong)(uVar1 >> 1);

      goto LAB_1402d6b46;

    }

  }

  *(undefined1 *)(param_1 + 0x4c) = 0;

LAB_1402d6b46:

  *(int *)(param_1 + 0x48) = (int)uVar5;

  return CONCAT71((int7)(uVar5 >> 8),1);

}




