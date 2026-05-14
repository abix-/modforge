// Address: 0x140185eb0
// Ghidra name: FUN_140185eb0
// ============ 0x140185eb0 FUN_140185eb0 (size=217) ============


ulonglong FUN_140185eb0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,

                       undefined4 param_5)



{

  undefined8 *puVar1;

  int iVar2;

  longlong lVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  

  if (*(int *)(param_1 + 0xc) == *(int *)(param_1 + 0x10)) {

    lVar3 = FUN_140184230(*(undefined8 *)(param_1 + 0x18),

                          (longlong)(*(int *)(param_1 + 0x10) + 1) << 3);

    uVar5 = 0;

    if (lVar3 != 0) {

      iVar2 = *(int *)(param_1 + 0x10);

      *(longlong *)(param_1 + 0x18) = lVar3;

      uVar4 = FUN_1401841f0(0x18);

      *(undefined8 *)(lVar3 + (longlong)iVar2 * 8) = uVar4;

      uVar5 = *(ulonglong *)(param_1 + 0x18);

      if (*(longlong *)(uVar5 + (longlong)*(int *)(param_1 + 0x10) * 8) != 0) {

        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

        goto LAB_140185f36;

      }

    }

    uVar5 = uVar5 & 0xffffffffffffff00;

  }

  else {

LAB_140185f36:

    puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x18) + (longlong)*(int *)(param_1 + 0xc) * 8)

    ;

    iVar2 = *(int *)(param_1 + 0xc) + 1;

    *(int *)(param_1 + 0xc) = iVar2;

    uVar5 = CONCAT71((uint7)(uint3)((uint)iVar2 >> 8),1);

    *(undefined4 *)(puVar1 + 1) = param_3;

    *(undefined4 *)((longlong)puVar1 + 0xc) = param_4;

    *(undefined4 *)(puVar1 + 2) = param_5;

    *puVar1 = param_2;

  }

  return uVar5;

}




