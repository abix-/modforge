// Address: 0x1400f0ca0
// Ghidra name: FUN_1400f0ca0
// ============ 0x1400f0ca0 FUN_1400f0ca0 (size=509) ============


undefined8 FUN_1400f0ca0(longlong param_1,longlong param_2,undefined4 param_3)



{

  byte bVar1;

  byte bVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  undefined4 uVar9;

  uint uVar10;

  byte *pbVar11;

  

  *(longlong *)(param_1 + 8) = param_2;

  *(undefined4 *)(param_1 + 0x10) = param_3;

  uVar3 = FUN_1400f4020(param_2,param_3,&DAT_1403102c0);

  iVar4 = FUN_1400f4020(param_2,param_3,&DAT_1403102c8);

  *(int *)(param_1 + 0x18) = iVar4;

  iVar5 = FUN_1400f4020(param_2,param_3,&DAT_14030d7f4);

  *(int *)(param_1 + 0x1c) = iVar5;

  iVar6 = FUN_1400f4020(param_2,param_3,&DAT_1403102d0);

  *(int *)(param_1 + 0x20) = iVar6;

  iVar7 = FUN_1400f4020(param_2,param_3,&DAT_1403102d8);

  *(int *)(param_1 + 0x24) = iVar7;

  iVar8 = FUN_1400f4020(param_2,param_3,&DAT_1403102e0);

  *(int *)(param_1 + 0x28) = iVar8;

  uVar9 = FUN_1400f4020(param_2,param_3,&DAT_14030b008);

  *(undefined4 *)(param_1 + 0x2c) = uVar9;

  if (((((uVar3 != 0) && (iVar4 != 0)) && (iVar5 != 0)) && ((iVar6 != 0 && (iVar7 != 0)))) &&

     (iVar8 != 0)) {

    uVar10 = FUN_1400f4020(param_2,param_3,&DAT_1403102e8);

    if (uVar10 == 0) {

      iVar4 = 0xffff;

    }

    else {

      iVar4 = (uint)*(byte *)((ulonglong)uVar10 + 5 + param_2) +

              (uint)*(byte *)((ulonglong)uVar10 + 4 + param_2) * 0x100;

    }

    *(int *)(param_1 + 0x14) = iVar4;

    iVar4 = 0;

    bVar1 = *(byte *)((ulonglong)uVar3 + 2 + param_2);

    bVar2 = *(byte *)((ulonglong)uVar3 + 3 + param_2);

    *(undefined4 *)(param_1 + 0x30) = 0;

    iVar5 = (uint)bVar2 + (uint)bVar1 * 0x100;

    if (iVar5 != 0) {

      do {

        pbVar11 = (byte *)((ulonglong)(uVar3 + 4 + iVar4 * 8) + param_2);

        if (((ushort)((ushort)pbVar11[1] + (ushort)*pbVar11 * 0x100) == 3) &&

           ((iVar6 = (uint)pbVar11[3] + (uint)pbVar11[2] * 0x100, iVar6 == 1 || (iVar6 == 10)))) {

          *(uint *)(param_1 + 0x30) =

               (uint)pbVar11[7] +

               ((uint)pbVar11[6] + ((uint)pbVar11[5] + (uint)pbVar11[4] * 0x100) * 0x100) * 0x100 +

               uVar3;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < iVar5);

    }

    if (*(int *)(param_1 + 0x30) != 0) {

      *(uint *)(param_1 + 0x34) =

           (uint)*(byte *)((longlong)*(int *)(param_1 + 0x1c) + 0x33 + param_2) +

           (uint)*(byte *)((longlong)*(int *)(param_1 + 0x1c) + 0x32 + param_2) * 0x100;

      return 1;

    }

  }

  return 0;

}




