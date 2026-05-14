// Address: 0x14022a9d0
// Ghidra name: FUN_14022a9d0
// ============ 0x14022a9d0 FUN_14022a9d0 (size=631) ============


undefined8

FUN_14022a9d0(longlong param_1,DWORD param_2,DWORD param_3,BOOL param_4,int *param_5,int *param_6,

             int *param_7,int *param_8,int param_9)



{

  code *pcVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  BOOL BVar5;

  longlong lVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  int iVar9;

  ulonglong uVar10;

  undefined8 in_stack_ffffffffffffffa8;

  int *piVar11;

  undefined4 uVar12;

  tagRECT local_48;

  

  lVar6 = FUN_14016dcf0();

  uVar8 = 0;

  uVar10 = uVar8;

  if (lVar6 != 0) {

    lVar6 = FUN_14016dcf0();

    uVar10 = *(ulonglong *)(lVar6 + 0x680);

  }

  if (param_9 == 0) {

    piVar11 = param_6;

    FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),param_5,

                  param_6);

    uVar12 = (undefined4)((ulonglong)piVar11 >> 0x20);

    *param_7 = *(int *)(param_1 + 0x20);

    uVar8 = (ulonglong)*(uint *)(param_1 + 0x24);

  }

  else if (param_9 == 1) {

    piVar11 = param_6;

    FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x70),param_5,

                  param_6);

    uVar12 = (undefined4)((ulonglong)piVar11 >> 0x20);

    *param_7 = *(int *)(param_1 + 0x74);

    uVar8 = (ulonglong)*(uint *)(param_1 + 0x78);

  }

  else if (param_9 == 2) {

    piVar11 = param_6;

    FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x7c),*(undefined4 *)(param_1 + 0x80),param_5,

                  param_6);

    uVar12 = (undefined4)((ulonglong)piVar11 >> 0x20);

    *param_7 = *(int *)(param_1 + 0x84);

    uVar8 = (ulonglong)*(uint *)(param_1 + 0x88);

  }

  else if (param_9 == 3) {

    piVar11 = param_6;

    FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0x90),param_5,

                  param_6);

    uVar12 = (undefined4)((ulonglong)piVar11 >> 0x20);

    *param_7 = *(int *)(param_1 + 0x94);

    uVar8 = (ulonglong)*(uint *)(param_1 + 0x98);

  }

  else {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e54a8,"WIN_AdjustWindowRectWithStyle",

                            "C:\\dev\\SDL-3.4.4\\src\\video\\windows\\SDL_windowswindow.c",0xc9);

      uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);

    } while (iVar3 == 0);

    if (iVar3 == 1) {

      pcVar1 = (code *)swi(3);

      uVar7 = (*pcVar1)();

      return uVar7;

    }

    *param_7 = 0;

  }

  local_48.bottom = (LONG)uVar8;

  *param_8 = local_48.bottom;

  local_48.right = *param_7;

  local_48.left = 0;

  local_48.top = 0;

  iVar3 = 0;

  iVar9 = 0;

  if ((*(uint *)(param_1 + 0x48) & 0xc0010) == 0) {

    uVar7 = FUN_14016dcf0();

    cVar2 = FUN_140181590(uVar7);

    if (cVar2 == '\0') {

      BVar5 = AdjustWindowRectEx(&local_48,param_2,param_4,param_3);

      if (BVar5 == 0) {

        uVar7 = FUN_1401a9ed0("AdjustWindowRectEx()");

        return uVar7;

      }

    }

    else if (uVar10 != 0) {

      if ((*(longlong *)(param_1 + 0x188) == 0) || (*(code **)(uVar10 + 0xc0) == (code *)0x0)) {

        uVar4 = 0x60;

      }

      else {

        uVar4 = (**(code **)(uVar10 + 0xc0))(*(undefined8 *)(*(longlong *)(param_1 + 0x188) + 8));

      }

      iVar3 = (**(code **)(uVar10 + 0xb8))(&local_48,param_2,param_4,param_3,CONCAT44(uVar12,uVar4))

      ;

      if (iVar3 == 0) {

        uVar7 = FUN_1401a9ed0("AdjustWindowRectExForDpi()");

        return uVar7;

      }

    }

    iVar3 = local_48.top;

    iVar9 = local_48.left;

  }

  *param_5 = *param_5 + iVar9;

  *param_6 = *param_6 + iVar3;

  *param_7 = local_48.right - iVar9;

  *param_8 = local_48.bottom - iVar3;

  return 1;

}




