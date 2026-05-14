// Address: 0x1401df840
// Ghidra name: FUN_1401df840
// ============ 0x1401df840 FUN_1401df840 (size=224) ============


undefined4 FUN_1401df840(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  ulonglong uVar10;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  iVar2 = FUN_14014df00(param_2);

  iVar3 = FUN_14014dee0(param_2);

  iVar4 = FUN_14014de80(param_2);

  iVar5 = FUN_14014dec0(param_2);

  iVar6 = FUN_14014dea0(param_2);

  uVar7 = FUN_14014de60(param_2);

  uVar10 = (ulonglong)uVar7;

  iVar8 = FUN_1401e0080(iVar2);

  if (iVar8 != 0) {

    iVar8 = FUN_1401e0080(iVar3);

    if (iVar8 != 0) {

      iVar8 = FUN_1401e0040(iVar4);

      if (iVar8 != 0) {

        iVar8 = FUN_1401e0080(iVar5);

        if (iVar8 != 0) {

          iVar8 = FUN_1401e0080(iVar6);

          iVar9 = (int)uVar10;

          if (((iVar8 != 0) && (iVar8 = FUN_1401e0040(uVar10 & 0xffffffff), iVar8 != 0)) &&

             ((*(char *)(lVar1 + 0x62) != '\0' ||

              (((iVar2 == iVar3 && (iVar5 == iVar6)) && (iVar4 == iVar9)))))) {

            return 1;

          }

        }

      }

    }

  }

  return 0;

}




