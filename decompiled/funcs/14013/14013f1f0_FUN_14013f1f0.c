// Address: 0x14013f1f0
// Ghidra name: FUN_14013f1f0
// ============ 0x14013f1f0 FUN_14013f1f0 (size=188) ============


longlong FUN_14013f1f0(int *param_1)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  undefined4 *puVar6;

  int iVar7;

  int local_res8 [2];

  

  iVar7 = 0;

  local_res8[0] = 0;

  lVar2 = FUN_140158f60(local_res8);

  if ((lVar2 != 0) && (iVar3 = local_res8[0] + -1, -1 < iVar3)) {

    iVar5 = 1;

    puVar6 = (undefined4 *)(lVar2 + (longlong)iVar3 * 4);

    lVar4 = lVar2 + (longlong)local_res8[0] * 4;

    do {

      cVar1 = FUN_14013f5e0(*puVar6);

      if (cVar1 == '\0') {

        FUN_1402f8e20(puVar6,lVar4,(longlong)iVar5 << 2);

      }

      else {

        iVar7 = iVar7 + 1;

        iVar5 = iVar5 + 1;

      }

      lVar4 = lVar4 + -4;

      puVar6 = puVar6 + -1;

      iVar3 = iVar3 + -1;

    } while (-1 < iVar3);

  }

  if (param_1 != (int *)0x0) {

    *param_1 = iVar7;

  }

  return lVar2;

}




