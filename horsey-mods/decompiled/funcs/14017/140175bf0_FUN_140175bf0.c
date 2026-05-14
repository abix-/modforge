// Address: 0x140175bf0
// Ghidra name: FUN_140175bf0
// ============ 0x140175bf0 FUN_140175bf0 (size=149) ============


undefined4 * FUN_140175bf0(int *param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  

  iVar1 = FUN_14021aed0();

  puVar3 = (undefined4 *)FUN_1401841f0((longlong)iVar1 * 4 + 4);

  if (puVar3 == (undefined4 *)0x0) {

    if (param_1 != (int *)0x0) {

      *param_1 = 0;

    }

  }

  else {

    if (param_1 != (int *)0x0) {

      *param_1 = iVar1;

    }

    iVar4 = 0;

    puVar6 = puVar3;

    iVar5 = 0;

    if (0 < iVar1) {

      do {

        uVar2 = FUN_14021ac70(iVar4);

        iVar4 = iVar4 + 1;

        *puVar6 = uVar2;

        puVar6 = puVar6 + 1;

        iVar5 = iVar1;

      } while (iVar4 < iVar1);

    }

    puVar3[iVar5] = 0;

  }

  return puVar3;

}




