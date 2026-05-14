// Address: 0x1400ef110
// Ghidra name: FUN_1400ef110
// ============ 0x1400ef110 FUN_1400ef110 (size=263) ============


void FUN_1400ef110(longlong param_1,ushort param_2)



{

  undefined1 *puVar1;

  int iVar2;

  undefined1 *puVar3;

  

  if (-1 < *(short *)(param_1 + 0x824 + (ulonglong)param_2 * 4)) {

    FUN_1400ef110();

  }

  if (*(int *)(param_1 + 0x4850) < *(int *)(param_1 + 0x4848)) {

    puVar3 = (undefined1 *)

             ((longlong)(*(int *)(param_1 + 0x484c) + *(int *)(param_1 + 0x4850)) +

             *(longlong *)(param_1 + 8));

    puVar1 = (undefined1 *)

             (*(longlong *)(param_1 + 0x4828) +

             (ulonglong)*(byte *)(param_1 + 0x827 + (ulonglong)param_2 * 4) * 4);

    if (0x7f < (byte)puVar1[3]) {

      *puVar3 = puVar1[2];

      puVar3[1] = puVar1[1];

      puVar3[2] = *puVar1;

      puVar3[3] = puVar1[3];

    }

    *(int *)(param_1 + 0x484c) = *(int *)(param_1 + 0x484c) + 4;

    if (*(int *)(param_1 + 0x4844) <= *(int *)(param_1 + 0x484c)) {

      *(undefined4 *)(param_1 + 0x484c) = *(undefined4 *)(param_1 + 0x483c);

      *(int *)(param_1 + 0x4850) = *(int *)(param_1 + 0x4850) + *(int *)(param_1 + 0x4834);

      iVar2 = *(int *)(param_1 + 0x4850);

      while ((*(int *)(param_1 + 0x4848) <= iVar2 && (iVar2 = *(int *)(param_1 + 0x4830), 0 < iVar2)

             )) {

        *(int *)(param_1 + 0x4830) = iVar2 + -1;

        iVar2 = *(int *)(param_1 + 0x4854) << ((byte)iVar2 & 0x1f);

        *(int *)(param_1 + 0x4834) = iVar2;

        iVar2 = *(int *)(param_1 + 0x4840) + (iVar2 >> 1);

        *(int *)(param_1 + 0x4850) = iVar2;

      }

    }

  }

  return;

}




