// Address: 0x1401785d0
// Ghidra name: FUN_1401785d0
// ============ 0x1401785d0 FUN_1401785d0 (size=229) ============


undefined1 * FUN_1401785d0(char *param_1)



{

  int iVar1;

  size_t sVar2;

  undefined1 *puVar3;

  longlong lVar4;

  longlong lVar5;

  undefined1 *puVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  char *local_res8 [2];

  undefined4 local_28 [4];

  

  local_res8[0] = param_1;

  sVar2 = strlen(param_1);

  lVar9 = (sVar2 + 1) * 0xc;

  puVar3 = (undefined1 *)FUN_1401841f0(lVar9);

  if (puVar3 == (undefined1 *)0x0) {

    return (undefined1 *)0x0;

  }

  iVar1 = FUN_14012ed20(local_res8,0);

  lVar7 = lVar9;

  puVar6 = puVar3;

  while (iVar1 != 0) {

    lVar5 = 0;

    iVar1 = FUN_14012e880(iVar1,local_28);

    lVar8 = (longlong)iVar1;

    if (0 < iVar1) {

      do {

        lVar4 = FUN_1401786c0(puVar6,local_28[lVar5],lVar7);

        lVar7 = lVar7 - lVar4;

        puVar6 = puVar6 + lVar4;

        lVar5 = lVar5 + 1;

      } while (lVar5 < lVar8);

    }

    iVar1 = FUN_14012ed20(local_res8,0);

  }

  *puVar6 = 0;

  if ((lVar7 + -1 != 0) &&

     (puVar6 = (undefined1 *)FUN_140184230(puVar3,lVar9 - (lVar7 + -1)), puVar6 != (undefined1 *)0x0

     )) {

    puVar3 = puVar6;

  }

  return puVar3;

}




