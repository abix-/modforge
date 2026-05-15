// Address: 0x1402783e0
// Ghidra name: FUN_1402783e0
// ============ 0x1402783e0 FUN_1402783e0 (size=338) ============


ulonglong FUN_1402783e0(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  ulonglong in_RAX;

  longlong lVar4;

  ulonglong uVar5;

  undefined8 uVar6;

  undefined1 local_res8;

  undefined1 local_res9;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(int *)(param_1 + 0x8c) < 1) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar4 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  uVar5 = FUN_140149350();

  iVar3 = FUN_140279b10(lVar1);

  while (0 < iVar3) {

    if (lVar4 != 0) {

      FUN_140278d10(lVar1);

    }

    *(ulonglong *)(lVar1 + 0x48) = uVar5;

    iVar3 = FUN_140279b10(lVar1);

  }

  if (*(longlong *)(lVar1 + 0x48) + 3000U <= uVar5) {

    iVar3 = -1;

  }

  if ((lVar4 != 0) && (*(int *)(lVar1 + 0x1c) != 0x83)) {

    if ((*(ulonglong *)(lVar1 + 0x58) != 0) && (*(ulonglong *)(lVar1 + 0x58) <= uVar5)) {

      FUN_1402785e0(lVar1);

      uVar6 = 0;

      cVar2 = FUN_140279690(lVar1);

      if (cVar2 == '\0') {

        *(undefined8 *)(lVar1 + 0x58) = uVar6;

      }

      else {

        FUN_140279d20();

      }

    }

    if ((*(longlong *)(lVar1 + 0x50) == 0) || (*(longlong *)(lVar1 + 0x50) + 900000U <= uVar5)) {

      local_res9 = *(undefined1 *)(lVar1 + 0x28);

      local_res8 = 0x15;

      FUN_140279fc0(lVar1,&local_res8,2,0);

      *(ulonglong *)(lVar1 + 0x50) = uVar5;

    }

  }

  if ((iVar3 < 0) || (*(char *)(lVar1 + 0x60) != '\0')) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (ulonglong)(byte)((byte)((uint)iVar3 >> 0x1f) ^ 1);

}




