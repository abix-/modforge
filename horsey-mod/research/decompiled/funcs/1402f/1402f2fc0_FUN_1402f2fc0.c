// Address: 0x1402f2fc0
// Ghidra name: FUN_1402f2fc0
// ============ 0x1402f2fc0 FUN_1402f2fc0 (size=399) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



BOOL FUN_1402f2fc0(__crt_locale_pointers *param_1,DWORD param_2,undefined8 param_3,

                  undefined4 param_4,LPWORD param_5,int param_6,int param_7)



{

  ulonglong uVar1;

  longlong lVar2;

  int iVar3;

  BOOL BVar4;

  ulonglong uVar5;

  undefined4 *puVar6;

  ulonglong uVar7;

  LPCWSTR lpSrcStr;

  undefined1 *puVar8;

  undefined1 *puVar9;

  BOOL BVar10;

  undefined1 auStack_88 [32];

  undefined8 local_68;

  undefined4 local_60;

  undefined4 local_58 [2];

  longlong local_50;

  longlong local_48;

  char local_38;

  ulonglong local_30;

  

  puVar8 = auStack_88;

  puVar9 = auStack_88;

  local_30 = DAT_1403e8b00 ^ (ulonglong)local_58;

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_50,param_1);

  if (param_6 == 0) {

    param_6 = *(int *)(local_48 + 0xc);

  }

  local_60 = 0;

  local_68 = 0;

  iVar3 = FUN_1402f3150(param_6,(-(param_7 != 0) & 8U) + 1,param_3,param_4);

  if (iVar3 == 0) {

    BVar10 = 0;

    puVar9 = auStack_88;

    goto LAB_1402f3116;

  }

  uVar1 = (longlong)iVar3 * 2;

  uVar7 = -(ulonglong)(uVar1 < uVar1 + 0x10) & uVar1 + 0x10;

  if (uVar7 == 0) {

    lpSrcStr = (LPCWSTR)0x0;

LAB_1402f30fe:

    BVar10 = 0;

    BVar4 = 0;

    if (lpSrcStr == (LPCWSTR)0x0) goto LAB_1402f3116;

  }

  else {

    if (uVar7 < 0x401) {

      uVar5 = uVar7 + 0xf;

      if (uVar5 <= uVar7) {

        uVar5 = 0xffffffffffffff0;

      }

      lVar2 = -(uVar5 & 0xfffffffffffffff0);

      puVar9 = auStack_88 + lVar2;

      puVar8 = auStack_88 + lVar2;

      puVar6 = (undefined4 *)((longlong)local_58 + lVar2);

      lpSrcStr = (LPCWSTR)0x0;

      if (puVar6 == (undefined4 *)0x0) goto LAB_1402f30fe;

      *puVar6 = 0xcccc;

LAB_1402f30ac:

      lpSrcStr = (LPCWSTR)(puVar6 + 4);

      puVar9 = puVar8;

    }

    else {

      puVar6 = (undefined4 *)_malloc_base();

      lpSrcStr = (LPCWSTR)0x0;

      puVar9 = auStack_88;

      if (puVar6 != (undefined4 *)0x0) {

        *puVar6 = 0xdddd;

        goto LAB_1402f30ac;

      }

    }

    if (lpSrcStr == (LPCWSTR)0x0) goto LAB_1402f30fe;

    *(undefined8 *)(puVar9 + -8) = 0x1402f30c2;

    FUN_1402f94c0(lpSrcStr,0,uVar1);

    *(int *)(puVar9 + 0x28) = iVar3;

    *(LPCWSTR *)(puVar9 + 0x20) = lpSrcStr;

    *(undefined8 *)(puVar9 + -8) = 0x1402f30de;

    iVar3 = FUN_1402f3150(param_6,1,param_3,param_4);

    if (iVar3 == 0) goto LAB_1402f30fe;

    *(undefined8 *)(puVar9 + -8) = 0x1402f30f8;

    BVar4 = GetStringTypeW(param_2,lpSrcStr,iVar3,param_5);

  }

  BVar10 = BVar4;

  if (*(int *)(lpSrcStr + -8) == 0xdddd) {

    *(undefined8 *)(puVar9 + -8) = 0x1402f3116;

    FUN_1402e9a80();

  }

LAB_1402f3116:

  if (local_38 != '\0') {

    *(uint *)(local_50 + 0x3a8) = *(uint *)(local_50 + 0x3a8) & 0xfffffffd;

  }

  *(undefined8 *)(puVar9 + -8) = 0x1402f3135;

  return BVar10;

}




