// Address: 0x1401f5770
// Ghidra name: FUN_1401f5770
// ============ 0x1401f5770 FUN_1401f5770 (size=295) ============


undefined8 FUN_1401f5770(longlong param_1,undefined4 param_2,longlong param_3,longlong param_4)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (param_3 == 0) {

LAB_1401f5827:

    if (param_4 != 0) {

      if (*(int *)(lVar1 + 0x28f0) == *(int *)(lVar1 + 0x28f4)) {

        lVar2 = FUN_140184230(*(undefined8 *)(lVar1 + 0x28e8),

                              (ulonglong)(*(int *)(lVar1 + 0x28f4) + 2) << 3);

        if (lVar2 == 0) goto LAB_1401f5852;

        *(int *)(lVar1 + 0x28f4) = *(int *)(lVar1 + 0x28f4) + 1;

        *(longlong *)(lVar1 + 0x28e8) = lVar2;

      }

      *(longlong *)(*(longlong *)(lVar1 + 0x28e8) + (ulonglong)*(uint *)(lVar1 + 0x28f0) * 8) =

           param_4;

      *(int *)(lVar1 + 0x28f0) = *(int *)(lVar1 + 0x28f0) + 1;

    }

    uVar3 = 1;

  }

  else {

    if (*(int *)(lVar1 + 0x28e0) != *(int *)(lVar1 + 0x28e4)) {

LAB_1401f57ff:

      *(undefined4 *)(*(longlong *)(lVar1 + 0x28d0) + (ulonglong)*(uint *)(lVar1 + 0x28e0) * 4) =

           param_2;

      *(longlong *)(*(longlong *)(lVar1 + 0x28d8) + (ulonglong)*(uint *)(lVar1 + 0x28e0) * 8) =

           param_3;

      *(int *)(lVar1 + 0x28e0) = *(int *)(lVar1 + 0x28e0) + 1;

      goto LAB_1401f5827;

    }

    lVar2 = FUN_140184230(*(undefined8 *)(lVar1 + 0x28d0),

                          (ulonglong)(*(int *)(lVar1 + 0x28e4) + 2) << 2);

    if (lVar2 != 0) {

      *(longlong *)(lVar1 + 0x28d0) = lVar2;

      lVar2 = FUN_140184230(*(undefined8 *)(lVar1 + 0x28d8),

                            (ulonglong)(*(int *)(lVar1 + 0x28e4) + 2) << 3);

      if (lVar2 != 0) {

        *(int *)(lVar1 + 0x28e4) = *(int *)(lVar1 + 0x28e4) + 1;

        *(longlong *)(lVar1 + 0x28d8) = lVar2;

        goto LAB_1401f57ff;

      }

    }

LAB_1401f5852:

    uVar3 = 0;

  }

  return uVar3;

}




