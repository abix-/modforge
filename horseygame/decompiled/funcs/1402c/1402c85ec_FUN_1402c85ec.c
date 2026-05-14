// Address: 0x1402c85ec
// Ghidra name: FUN_1402c85ec
// ============ 0x1402c85ec FUN_1402c85ec (size=229) ============


longlong * FUN_1402c85ec(longlong *param_1,DWORD64 *param_2,longlong param_3,longlong *param_4)



{

  longlong lVar1;

  uint uVar2;

  DWORD64 DVar3;

  int iVar4;

  PRUNTIME_FUNCTION p_Var5;

  uint uVar6;

  ulonglong uVar7;

  int *piVar8;

  uint uVar9;

  longlong lVar10;

  ulonglong local_res8;

  

  uVar9 = *(uint *)(param_3 + 0xc);

  iVar4 = FUN_1402c9a3c(param_3);

  *param_4 = *param_1;

  do {

    do {

      if (uVar9 == 0) {

        return param_4;

      }

      uVar9 = uVar9 - 1;

      DVar3 = param_2[1];

      lVar1 = (longlong)*(int *)(param_3 + 0x10) + (ulonglong)uVar9 * 0x14;

    } while ((iVar4 <= *(int *)(lVar1 + 4 + DVar3)) || (*(int *)(lVar1 + 8 + DVar3) < iVar4));

    p_Var5 = RtlLookupFunctionEntry(*param_2,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);

    uVar7 = 0;

    lVar10 = (longlong)*(int *)(lVar1 + 0x10 + DVar3) + local_res8;

    uVar2 = *(uint *)(lVar1 + 0xc + DVar3);

    if (uVar2 != 0) {

      piVar8 = (int *)(lVar10 + 0xc);

      do {

        if ((longlong)*piVar8 == (ulonglong)p_Var5->BeginAddress) goto LAB_1402c869d;

        uVar6 = (int)uVar7 + 1;

        uVar7 = (ulonglong)uVar6;

        piVar8 = piVar8 + 5;

      } while (uVar6 < uVar2);

    }

  } while (uVar2 <= (uint)uVar7);

LAB_1402c869d:

  *param_4 = *(longlong *)((longlong)*(int *)(lVar10 + 0x10 + uVar7 * 0x14) + *param_1);

  return param_4;

}




