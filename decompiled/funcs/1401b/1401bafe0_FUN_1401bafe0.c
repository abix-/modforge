// Address: 0x1401bafe0
// Ghidra name: FUN_1401bafe0
// ============ 0x1401bafe0 FUN_1401bafe0 (size=190) ============


ulonglong FUN_1401bafe0(undefined8 param_1,ulonglong *param_2,longlong param_3)



{

  uint uVar1;

  uint uVar2;

  ulonglong in_RAX;

  ulonglong *puVar3;

  uint uVar4;

  uint uVar5;

  

  uVar1 = (uint)param_2[8];

  if ((uVar1 == *(uint *)(param_3 + 0x40)) &&

     (uVar2 = (uint)param_2[0x11], uVar2 == *(uint *)(param_3 + 0x88))) {

    uVar5 = 0;

    uVar4 = 0;

    puVar3 = param_2;

    if (uVar1 != 0) {

      do {

        in_RAX = *(ulonglong *)((longlong)puVar3 + (param_3 - (longlong)param_2));

        if (*puVar3 != in_RAX) goto LAB_1401bb091;

        uVar4 = uVar4 + 1;

        puVar3 = puVar3 + 1;

      } while (uVar4 < uVar1);

    }

    if (uVar2 != 0) {

      puVar3 = param_2 + 9;

      do {

        in_RAX = *(ulonglong *)((longlong)puVar3 + (param_3 - (longlong)param_2));

        if (*puVar3 != in_RAX) goto LAB_1401bb091;

        uVar5 = uVar5 + 1;

        puVar3 = puVar3 + 1;

      } while (uVar5 < uVar2);

    }

    in_RAX = *(ulonglong *)(param_3 + 0x90);

    if ((param_2[0x12] == in_RAX) &&

       (in_RAX = (ulonglong)*(uint *)(param_3 + 0x98),

       (uint)param_2[0x13] == *(uint *)(param_3 + 0x98))) {

      return (ulonglong)

             CONCAT31((int3)((uint)*(int *)(param_3 + 0x9c) >> 8),

                      *(int *)((longlong)param_2 + 0x9c) == *(int *)(param_3 + 0x9c));

    }

  }

LAB_1401bb091:

  return in_RAX & 0xffffffffffffff00;

}




