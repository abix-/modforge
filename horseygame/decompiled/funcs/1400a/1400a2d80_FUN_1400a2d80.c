// Address: 0x1400a2d80
// Ghidra name: FUN_1400a2d80
// ============ 0x1400a2d80 FUN_1400a2d80 (size=321) ============


void FUN_1400a2d80(longlong param_1,longlong param_2,longlong param_3)



{

  bool bVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  int iVar8;

  ulonglong uVar9;

  

  uVar9 = 0;

  iVar2 = -1;

  if ((*(char *)(param_1 + 0x6b) == '\x01') && (iVar2 = -1, *(char *)(param_1 + 0x15b) == '\x01')) {

    iVar2 = 0;

  }

  uVar7 = uVar9;

  iVar8 = iVar2;

  if (((*(char *)(param_2 + 0x6b) == '\x01') && (*(char *)(param_2 + 0x15b) == '\x01')) &&

     (iVar8 = 1, iVar2 == 0)) {

    iVar8 = -1;

  }

  do {

    iVar2 = FUN_1400c6580();

    uVar5 = uVar9;

    do {

      if (((uVar5 < 0x61) || (0xae < uVar5)) && (0xe < uVar5 - 0x48)) {

        if ((0xe < uVar5 - 0xb7) || ((0x48c3UL >> (uVar5 - 0xb7 & 0x3f) & 1) == 0))

        goto LAB_1400a2e23;

LAB_1400a2eba:

        bVar1 = true;

      }

      else {

        if ((uVar5 != 0x6b) && (uVar5 != 0x53)) goto LAB_1400a2eba;

LAB_1400a2e23:

        bVar1 = false;

      }

      iVar3 = (int)uVar7;

      if ((iVar8 != -1) && (iVar3 = 1 - iVar8, bVar1)) {

        iVar3 = iVar8;

      }

      lVar4 = param_2;

      if (iVar3 == 0) {

        lVar4 = param_1;

      }

      *(undefined1 *)(param_3 + uVar5) = *(undefined1 *)((longlong)iVar2 * 0xf0 + uVar5 + lVar4);

      iVar2 = FUN_1400c6580();

      uVar5 = uVar5 + 1;

    } while ((longlong)uVar5 < 0xf0);

    uVar6 = (int)uVar7 + 1;

    param_3 = param_3 + 0xf0;

    uVar7 = (ulonglong)uVar6;

    if (1 < (int)uVar6) {

      return;

    }

  } while( true );

}




