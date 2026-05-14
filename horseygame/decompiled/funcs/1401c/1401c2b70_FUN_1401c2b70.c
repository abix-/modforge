// Address: 0x1401c2b70
// Ghidra name: FUN_1401c2b70
// ============ 0x1401c2b70 FUN_1401c2b70 (size=440) ============


void FUN_1401c2b70(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  uint uVar3;

  ulonglong uVar4;

  undefined8 local_res8;

  undefined1 local_88 [128];

  

  if (*(longlong *)(param_1 + 0x1e0) == 0) {

    FUN_1401cb360();

  }

  (**(code **)(**(longlong **)(param_1 + 0x120) + 200))

            (*(longlong **)(param_1 + 0x120),*(undefined8 *)(param_2 + 0x18));

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0xe8))

            (*(longlong **)(param_1 + 0x120),**(undefined8 **)(param_2 + 0x20));

  *(longlong *)(param_1 + 0x1d8) = param_2;

  uVar4 = 0;

  *(undefined4 *)(param_1 + 0x21f) = 0x1010101;

  *(undefined2 *)(param_1 + 0x223) = 0x101;

  *(undefined1 *)(param_1 + 0x225) = 1;

  if (*(int *)(param_2 + 0x14) != 0) {

    do {

      lVar1 = param_1 + uVar4 * 8;

      if (*(longlong *)(lVar1 + 0x940) == 0) {

        uVar2 = FUN_1401c5990(param_1);

        *(undefined8 *)(lVar1 + 0x940) = uVar2;

      }

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_2 + 0x14));

  }

  FUN_1401cb690(param_1,param_2);

  if (*(uint *)(param_2 + 0xc) != 0) {

    FUN_1402f8e20(local_88,param_1 + 0x830,(ulonglong)*(uint *)(param_2 + 0xc) << 3);

    FUN_1401cbc70(param_1,0,local_88,*(undefined4 *)(param_1 + 0x8f0),&local_res8);

    (**(code **)(**(longlong **)(param_1 + 0x120) + 0xf8))

              (*(longlong **)(param_1 + 0x120),

               *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x1d8) + 0x20) + 0x18),

               local_res8);

  }

  if (*(uint *)(param_2 + 0x10) != 0) {

    FUN_1402f8e20(local_88,param_1 + 0x870,(ulonglong)*(uint *)(param_2 + 0x10) << 3);

    FUN_1401cbc70(param_1,0,local_88,*(undefined4 *)(param_1 + 0x938),&local_res8);

    (**(code **)(**(longlong **)(param_1 + 0x120) + 0xf8))

              (*(longlong **)(param_1 + 0x120),

               *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x1d8) + 0x20) + 0x1c),

               local_res8);

  }

  return;

}




