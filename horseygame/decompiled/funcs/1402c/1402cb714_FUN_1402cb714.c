// Address: 0x1402cb714
// Ghidra name: FUN_1402cb714
// ============ 0x1402cb714 FUN_1402cb714 (size=676) ============


undefined8

FUN_1402cb714(int *param_1,__uint64 *param_2,undefined8 param_3,_xDISPATCHER_CONTEXT *param_4,

             FuncInfo4 *param_5,int param_6,undefined8 param_7,byte param_8)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  uint uVar4;

  uint uVar5;

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar6;

  undefined8 in_stack_ffffffffffffffa0;

  undefined4 uVar7;

  int local_48 [12];

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);

  __except_validate_context_record(param_3);

  lVar2 = FUN_1402c97f8();

  uVar5 = 0;

  if ((*(int *)(lVar2 + 0x40) == 0) && (*param_1 != -0x1f928c9d)) {

    if (*param_1 == -0x7fffffd7) {

      if (param_1[6] == 0xf) {

        if (*(longlong *)(param_1 + 0x18) == 0x19930520) goto LAB_1402cb796;

        goto LAB_1402cb788;

      }

    }

    else {

LAB_1402cb788:

      if (*param_1 == -0x7fffffda) goto LAB_1402cb796;

    }

    if (((byte)*param_5 & 0x20) != 0) {

      return 1;

    }

  }

LAB_1402cb796:

  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {

    FUN_1402cba94(local_48,param_5,*(undefined8 *)(param_4 + 8));

    if ((local_48[0] == 0) && (((byte)*param_5 & 0x40) == 0)) {

      return 1;

    }

    if (((*param_1 == -0x1f928c9d) &&

        (((2 < (uint)param_1[6] && (0x19930522 < (uint)param_1[8])) &&

         (iVar1 = *(int *)(*(longlong *)(param_1 + 0xc) + 8), iVar1 != 0)))) &&

       (lVar2 = FUN_1402c8e64(), lVar2 + iVar1 != 0)) {

      uVar3 = (*(code *)PTR__guard_dispatch_icall_140302c68)

                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,

                         CONCAT44(uVar7,(uint)param_8));

      return uVar3;

    }

    FUN_1402ca7bc(param_1,param_2,param_3,param_4,param_5,param_8,CONCAT44(uVar6,param_6),param_7);

    return 1;

  }

  if (*(int *)(param_5 + 8) == 0) {

    return 1;

  }

  uVar4 = *(byte *)(*(longlong *)(param_4 + 8) + (longlong)*(int *)(param_5 + 8)) & 0xf;

  if (*(uint *)((byte *)(*(longlong *)(param_4 + 8) + (longlong)*(int *)(param_5 + 8)) +

               (-4 - (longlong)(char)(&DAT_1403872c0)[uVar4])) >> ((&DAT_1403872d0)[uVar4] & 0x1f)

      == 0) {

    return 1;

  }

  if (param_6 != 0) {

    return 1;

  }

  if ((*(byte *)(param_1 + 1) & 0x20) == 0) {

LAB_1402cb8b2:

    __FrameHandler4::FrameUnwindToEmptyState(param_2,param_4,param_5);

  }

  else {

    if (*param_1 == -0x7fffffda) {

      iVar1 = FUN_1402c9ab4(param_5,param_4,*(undefined8 *)(param_4 + 0x20));

      if (iVar1 < -1) {

LAB_1402cb9b3:

                    /* WARNING: Subroutine does not return */

        FUN_1402e1bf8();

      }

      if (*(int *)(param_5 + 8) != 0) {

        uVar5 = *(byte *)(*(longlong *)(param_4 + 8) + (longlong)*(int *)(param_5 + 8)) & 0xf;

        uVar5 = *(uint *)((byte *)(*(longlong *)(param_4 + 8) + (longlong)*(int *)(param_5 + 8)) +

                         (-4 - (longlong)(char)(&DAT_1403872c0)[uVar5])) >>

                ((&DAT_1403872d0)[uVar5] & 0x1f);

      }

      if ((int)uVar5 <= iVar1) goto LAB_1402cb9b3;

    }

    else {

      if (*param_1 != -0x7fffffd7) goto LAB_1402cb8b2;

      if ((param_1[0xe] < -1) ||

         (uVar5 = *(byte *)(*(longlong *)(param_4 + 8) + (longlong)*(int *)(param_5 + 8)) & 0xf,

         (int)(*(uint *)((byte *)(*(longlong *)(param_4 + 8) + (longlong)*(int *)(param_5 + 8)) +

                        (-4 - (longlong)(char)(&DAT_1403872c0)[uVar5])) >>

              ((&DAT_1403872d0)[uVar5] & 0x1f)) <= param_1[0xe])) goto LAB_1402cb9b3;

      param_2 = *(__uint64 **)(param_1 + 10);

    }

    FUN_1402cc3e0(param_2,param_4,param_5);

  }

  return 1;

}




