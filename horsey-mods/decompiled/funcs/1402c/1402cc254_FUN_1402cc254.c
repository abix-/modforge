// Address: 0x1402cc254
// Ghidra name: FUN_1402cc254
// ============ 0x1402cc254 FUN_1402cc254 (size=361) ============


void FUN_1402cc254(__uint64 *param_1,undefined8 param_2,_s_FuncInfo *param_3,int param_4)



{

  int iVar1;

  int iVar2;

  undefined8 uVar3;

  longlong lVar4;

  longlong lVar5;

  

  uVar3 = FUN_1402c8e50();

  iVar2 = FUN_1402c99a0(param_1,param_2,param_3);

  lVar4 = FUN_1402c97f8();

  *(int *)(lVar4 + 0x30) = *(int *)(lVar4 + 0x30) + 1;

  while ((iVar2 != -1 && (param_4 < iVar2))) {

    if ((iVar2 < 0) || (param_3->maxState <= iVar2)) {

                    /* WARNING: Subroutine does not return */

      FUN_1402e1bf8();

    }

    lVar4 = FUN_1402c8e50();

    lVar5 = (longlong)iVar2 * 8;

    iVar2 = *(int *)((int)param_3->dispUnwindMap + lVar5 + lVar4);

    iVar1 = param_3->dispUnwindMap;

    lVar4 = FUN_1402c8e50();

    if (*(int *)(lVar4 + lVar5 + 4 + (longlong)iVar1) == 0) {

      lVar4 = 0;

    }

    else {

      iVar1 = param_3->dispUnwindMap;

      lVar4 = FUN_1402c8e50();

      iVar1 = *(int *)(lVar4 + lVar5 + 4 + (longlong)iVar1);

      lVar4 = FUN_1402c8e50();

      lVar4 = lVar4 + iVar1;

    }

    if (lVar4 != 0) {

      __FrameHandler3::SetState(param_1,param_3,iVar2);

      iVar1 = param_3->dispUnwindMap;

      lVar4 = FUN_1402c8e50();

      if (*(int *)(lVar4 + lVar5 + 4 + (longlong)iVar1) == 0) {

        lVar4 = 0;

      }

      else {

        iVar1 = param_3->dispUnwindMap;

        lVar4 = FUN_1402c8e50();

        iVar1 = *(int *)(lVar4 + lVar5 + 4 + (longlong)iVar1);

        lVar4 = FUN_1402c8e50();

        lVar4 = lVar4 + iVar1;

      }

      _CallSettingFrame(lVar4,param_1,0x103);

      FUN_1402c8e78(uVar3);

    }

  }

  lVar4 = FUN_1402c97f8();

  if (0 < *(int *)(lVar4 + 0x30)) {

    lVar4 = FUN_1402c97f8();

    *(int *)(lVar4 + 0x30) = *(int *)(lVar4 + 0x30) + -1;

  }

  if ((iVar2 != -1) && (param_4 < iVar2)) {

                    /* WARNING: Subroutine does not return */

    FUN_1402e1bf8();

  }

  __FrameHandler3::SetState(param_1,param_3,iVar2);

  return;

}




