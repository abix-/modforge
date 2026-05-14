// Address: 0x140198ee0
// Ghidra name: FUN_140198ee0
// ============ 0x140198ee0 FUN_140198ee0 (size=728) ============


LPCWSTR FUN_140198ee0(undefined8 *param_1,UINT param_2,undefined1 *param_3,uint param_4)



{

  int iVar1;

  uint uVar2;

  LPCWSTR pWVar3;

  LPCWSTR lpNewItem;

  undefined8 *puVar4;

  HMENU pHVar5;

  undefined8 uVar6;

  longlong lVar7;

  uint uVar8;

  longlong lVar9;

  UINT UVar10;

  undefined1 *puVar11;

  bool bVar12;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14033b0b8);

    return (LPCWSTR)0x0;

  }

  if (((int)param_2 < -1) || (UVar10 = *(UINT *)(param_1 + 1), (int)UVar10 < (int)param_2)) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14033b0dc);

    return (LPCWSTR)0x0;

  }

  if ((param_2 != 0xffffffff) && (bVar12 = param_2 == UVar10, UVar10 = param_2, bVar12)) {

    param_2 = 0xffffffff;

  }

  pWVar3 = (LPCWSTR)FUN_1401841a0(1,0x1030);

  if (pWVar3 == (LPCWSTR)0x0) {

    return (LPCWSTR)0x0;

  }

  lpNewItem = (LPCWSTR)0x0;

  if ((param_3 == (undefined1 *)0x0) ||

     (lpNewItem = (LPCWSTR)FUN_1401997c0(param_3), lpNewItem != (LPCWSTR)0x0)) {

    *(undefined8 **)pWVar3 = param_1;

    *(uint *)(pWVar3 + 0x808) = param_4;

    puVar11 = &DAT_14039bcb9;

    if (param_3 != (undefined1 *)0x0) {

      puVar11 = param_3;

    }

    pWVar3[0x80c] = L'\0';

    pWVar3[0x80d] = L'\0';

    pWVar3[0x80e] = L'\0';

    pWVar3[0x80f] = L'\0';

    pWVar3[0x810] = L'\0';

    pWVar3[0x811] = L'\0';

    pWVar3[0x812] = L'\0';

    pWVar3[0x813] = L'\0';

    pWVar3[0x814] = L'\0';

    pWVar3[0x815] = L'\0';

    pWVar3[0x816] = L'\0';

    pWVar3[0x817] = L'\0';

    FUN_14012ef10(pWVar3 + 8,0x1000,&DAT_14039bf30,puVar11);

    if ((param_3 == (undefined1 *)0x0) || ((param_4 & 4) == 0)) {

      uVar6 = FUN_140199930();

    }

    else {

      puVar4 = (undefined8 *)FUN_1401841a0(1,0x28);

      *(undefined8 **)(pWVar3 + 0x814) = puVar4;

      if (puVar4 == (undefined8 *)0x0) {

        FUN_1401841e0(pWVar3);

        pWVar3 = lpNewItem;

        goto LAB_140198f91;

      }

      pHVar5 = CreatePopupMenu();

      *puVar4 = pHVar5;

      *(undefined4 *)(*(longlong *)(pWVar3 + 0x814) + 8) = 0;

      *(undefined8 *)(*(longlong *)(pWVar3 + 0x814) + 0x10) = 0;

      *(LPCWSTR *)(*(longlong *)(pWVar3 + 0x814) + 0x20) = pWVar3;

      *(undefined8 *)(*(longlong *)(pWVar3 + 0x814) + 0x18) = 0;

      uVar6 = **(undefined8 **)(pWVar3 + 0x814);

    }

    *(undefined8 *)(pWVar3 + 4) = uVar6;

    lVar7 = FUN_140184230(param_1[2],(longlong)*(int *)(param_1 + 1) * 8 + 0x10);

    if (lVar7 != 0) {

      iVar1 = *(int *)(param_1 + 1);

      param_1[2] = lVar7;

      *(int *)(param_1 + 1) = iVar1 + 1;

      for (lVar9 = (longlong)iVar1; (int)UVar10 < lVar9; lVar9 = lVar9 + -1) {

        puVar4 = (undefined8 *)(param_1[2] + lVar9 * 8);

        *puVar4 = puVar4[-1];

      }

      *(LPCWSTR *)(lVar7 + (longlong)(int)UVar10 * 8) = pWVar3;

      *(undefined8 *)(lVar7 + (longlong)*(int *)(param_1 + 1) * 8) = 0;

      if (param_3 != (undefined1 *)0x0) {

        uVar2 = 0x10;

        if ((param_4 & 4) == 0) {

          uVar2 = 0x400;

        }

        uVar8 = uVar2 | 3;

        if (-1 < (int)param_4) {

          uVar8 = uVar2;

        }

        UVar10 = uVar8 | 8;

        if ((param_4 >> 0x1e & 1) == 0) {

          UVar10 = uVar8;

        }

        InsertMenuW((HMENU)*param_1,param_2,UVar10,*(UINT_PTR *)(pWVar3 + 4),lpNewItem);

        FUN_1401841e0(lpNewItem);

        return pWVar3;

      }

      InsertMenuW((HMENU)*param_1,param_2,0xc00,*(UINT_PTR *)(pWVar3 + 4),(LPCWSTR)0x0);

      return pWVar3;

    }

    FUN_1401841e0(pWVar3);

    FUN_1401841e0(lpNewItem);

    if (*(undefined8 **)(pWVar3 + 0x814) == (undefined8 *)0x0) {

      return (LPCWSTR)0x0;

    }

    DestroyMenu((HMENU)**(undefined8 **)(pWVar3 + 0x814));

    pWVar3 = *(LPCWSTR *)(pWVar3 + 0x814);

  }

LAB_140198f91:

  FUN_1401841e0(pWVar3);

  return (LPCWSTR)0x0;

}




