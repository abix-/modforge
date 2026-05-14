// Address: 0x1402cb9bc
// Ghidra name: thunk_FUN_1402cb4e0
// ============ 0x1402cb9bc thunk_FUN_1402cb4e0 (size=5) ============


undefined8

thunk_FUN_1402cb4e0(int *param_1,__uint64 *param_2,undefined8 param_3,_xDISPATCHER_CONTEXT *param_4,

                   _s_FuncInfo *param_5,int param_6,undefined8 param_7,byte param_8)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined4 uVar4;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar5;

  undefined8 in_stack_ffffffffffffffd0;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);

  __except_validate_context_record(param_3);

  lVar2 = FUN_1402c97f8();

  if ((*(int *)(lVar2 + 0x40) == 0) && (*param_1 != -0x1f928c9d)) {

    if (*param_1 == -0x7fffffd7) {

      if (param_1[6] == 0xf) {

        if (*(longlong *)(param_1 + 0x18) == 0x19930520) goto LAB_1402cb565;

        goto LAB_1402cb54b;

      }

    }

    else {

LAB_1402cb54b:

      if (*param_1 == -0x7fffffda) goto LAB_1402cb565;

    }

    if ((0x19930521 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff)) &&

       ((param_5->EHFlags & 1) != 0)) {

      return 1;

    }

  }

LAB_1402cb565:

  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {

    if ((param_5->nTryBlocks == 0) &&

       ((((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930521 ||

         (iVar1 = param_5->dispESTypeList, iVar1 == 0)) ||

        (lVar2 = FUN_1402c8e50(), lVar2 + iVar1 == 0)))) {

      if ((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930522) {

        return 1;

      }

      if (((uint)param_5->EHFlags >> 2 & 1) == 0) {

        return 1;

      }

    }

    if (((*param_1 == -0x1f928c9d) && (2 < (uint)param_1[6])) &&

       ((0x19930522 < (uint)param_1[8] &&

        ((iVar1 = *(int *)(*(longlong *)(param_1 + 0xc) + 8), iVar1 != 0 &&

         (lVar2 = FUN_1402c8e64(), lVar2 + iVar1 != 0)))))) {

      uVar3 = (*(code *)PTR__guard_dispatch_icall_140302c68)

                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,

                         CONCAT44(uVar5,(uint)param_8));

      return uVar3;

    }

    FUN_1402ca2c4(param_1,param_2,param_3,param_4,param_5,param_8,CONCAT44(uVar4,param_6),param_7);

    return 1;

  }

  if (param_5->maxState == 0) {

    return 1;

  }

  if (param_6 != 0) {

    return 1;

  }

  if ((*(byte *)(param_1 + 1) & 0x20) == 0) {

LAB_1402cb5eb:

    __FrameHandler3::FrameUnwindToEmptyState(param_2,param_4,param_5);

  }

  else {

    if (*param_1 == -0x7fffffda) {

      iVar1 = FUN_1402c9a4c(param_5,param_4,*(undefined8 *)(param_4 + 0x20));

      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) {

LAB_1402cb70b:

                    /* WARNING: Subroutine does not return */

        FUN_1402e1bf8();

      }

    }

    else {

      if (*param_1 != -0x7fffffd7) goto LAB_1402cb5eb;

      iVar1 = param_1[0xe];

      if ((iVar1 < -1) || (param_5->maxState <= iVar1)) goto LAB_1402cb70b;

      param_2 = *(__uint64 **)(param_1 + 10);

    }

    FUN_1402cc254(param_2,param_4,param_5,iVar1);

  }

  return 1;

}




