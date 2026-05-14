// Address: 0x1401bce00
// Ghidra name: FUN_1401bce00
// ============ 0x1401bce00 FUN_1401bce00 (size=283) ============


ulonglong FUN_1401bce00(undefined8 param_1,longlong param_2,longlong param_3)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  ulonglong in_RAX;

  uint *puVar4;

  uint uVar5;

  uint uVar6;

  longlong lVar7;

  

  uVar1 = *(uint *)(param_2 + 0x60);

  if (((uVar1 == *(uint *)(param_3 + 0x60)) &&

      (uVar2 = *(uint *)(param_2 + 0x84), uVar2 == *(uint *)(param_3 + 0x84))) &&

     (in_RAX = (ulonglong)*(uint *)(param_3 + 0x9c),

     *(uint *)(param_2 + 0x9c) == *(uint *)(param_3 + 0x9c))) {

    uVar5 = 0;

    lVar7 = param_3 - param_2;

    uVar6 = 0;

    if (uVar1 != 0) {

      puVar4 = (uint *)(param_2 + 4);

      do {

        uVar3 = *(uint *)(lVar7 + -4 + (longlong)puVar4);

        in_RAX = (ulonglong)uVar3;

        if (((puVar4[-1] != uVar3) ||

            (in_RAX = (ulonglong)*(uint *)(lVar7 + (longlong)puVar4),

            *puVar4 != *(uint *)(lVar7 + (longlong)puVar4))) ||

           (uVar3 = *(uint *)(lVar7 + 4 + (longlong)puVar4), in_RAX = (ulonglong)uVar3,

           puVar4[1] != uVar3)) goto LAB_1401bcf0e;

        uVar6 = uVar6 + 1;

        puVar4 = puVar4 + 3;

      } while (uVar6 < uVar1);

    }

    if (uVar2 != 0) {

      puVar4 = (uint *)(param_2 + 100);

      do {

        in_RAX = (ulonglong)*(uint *)(lVar7 + (longlong)puVar4);

        if (*puVar4 != *(uint *)(lVar7 + (longlong)puVar4)) goto LAB_1401bcf0e;

        uVar5 = uVar5 + 1;

        puVar4 = puVar4 + 1;

      } while (uVar5 < uVar2);

    }

    in_RAX = (ulonglong)*(uint *)(param_3 + 0x88);

    if (((*(uint *)(param_2 + 0x88) == *(uint *)(param_3 + 0x88)) &&

        (in_RAX = (ulonglong)*(uint *)(param_3 + 0x8c),

        *(uint *)(param_2 + 0x8c) == *(uint *)(param_3 + 0x8c))) &&

       ((in_RAX = (ulonglong)*(uint *)(param_3 + 0x90),

        *(uint *)(param_2 + 0x90) == *(uint *)(param_3 + 0x90) &&

        (in_RAX = (ulonglong)*(uint *)(param_3 + 0x94),

        *(uint *)(param_2 + 0x94) == *(uint *)(param_3 + 0x94))))) {

      return (ulonglong)

             CONCAT31((int3)((uint)*(int *)(param_3 + 0x98) >> 8),

                      *(int *)(param_2 + 0x98) == *(int *)(param_3 + 0x98));

    }

  }

LAB_1401bcf0e:

  return in_RAX & 0xffffffffffffff00;

}




