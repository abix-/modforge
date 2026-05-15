// Address: 0x1401caf50
// Ghidra name: FUN_1401caf50
// ============ 0x1401caf50 FUN_1401caf50 (size=378) ============


ulonglong FUN_1401caf50(longlong param_1,longlong param_2)



{

  int iVar1;

  ulonglong uVar2;

  uint uVar3;

  ulonglong uVar4;

  longlong lVar5;

  uint uVar6;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 local_38;

  undefined4 local_34;

  

  FUN_1401cd410();

  uVar3 = (uint)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  uVar4 = 0;

  uVar2 = uVar4;

  if (*(int *)(param_2 + 0x120) != 0) {

    do {

      lVar5 = uVar2 * 0x50 + param_2;

      FUN_1401cade0(*(longlong *)(lVar5 + 0x58) + 0x28);

      FUN_1401cade0(*(undefined8 *)(*(longlong *)(*(longlong *)(lVar5 + 0x58) + 0x10) + 0x18));

      FUN_1401841e0(*(undefined8 *)(*(longlong *)(*(longlong *)(lVar5 + 0x58) + 0x10) + 0x18));

      FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar5 + 0x58) + 0x10));

      FUN_1401841e0(*(undefined8 *)(lVar5 + 0x58));

      FUN_1401841e0(*(undefined8 *)(lVar5 + 0x60));

      uVar3 = (uint)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

      uVar6 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar6;

    } while (uVar6 < *(uint *)(param_2 + 0x120));

  }

  iVar1 = (**(code **)(**(longlong **)(param_2 + 0x18) + 0x68))

                    (*(longlong **)(param_2 + 0x18),0,0,0,(ulonglong)uVar3 << 0x20,

                     -(uint)(*(int *)(param_1 + 0x60) != 0) & 0x800);

  if (-1 < iVar1) {

    if (*(int *)(param_2 + 0x120) != 0) {

      do {

        uVar2 = FUN_1401ca1e0(param_1,*(undefined8 *)(param_2 + 0x18),

                              *(undefined4 *)(param_2 + 0x24),uVar4,uVar4 * 0x50 + 0x30 + param_2);

        if ((char)uVar2 == '\0') goto LAB_1401cb034;

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

      } while (uVar3 < *(uint *)(param_2 + 0x120));

    }

    (**(code **)(**(longlong **)(param_2 + 0x18) + 0x90))(*(longlong **)(param_2 + 0x18),&local_38);

    *(undefined4 *)(param_2 + 0x140) = local_38;

    *(undefined4 *)(param_2 + 0x144) = local_34;

    *(undefined1 *)(param_2 + 0x148) = 0;

    return CONCAT71((uint7)(uint3)((uint)local_34 >> 8),1);

  }

  uVar2 = FUN_1401cb240(param_1,"Could not resize swapchain buffers",iVar1);

LAB_1401cb034:

  return uVar2 & 0xffffffffffffff00;

}




