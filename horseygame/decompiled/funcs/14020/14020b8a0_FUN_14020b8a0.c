// Address: 0x14020b8a0
// Ghidra name: FUN_14020b8a0
// ============ 0x14020b8a0 FUN_14020b8a0 (size=322) ============


ulonglong FUN_14020b8a0(short *param_1,longlong param_2,char param_3)



{

  ushort uVar1;

  uint uVar2;

  int iVar3;

  ulonglong uVar4;

  

  uVar2 = *(uint *)(param_2 + 0x10) & 0x3fff;

  uVar4 = (ulonglong)uVar2;

  if ((((uVar2 != *(uint *)(param_1 + 8)) ||

       (iVar3 = (int)(*(double *)(param_2 + 0x28) * DAT_1403502f0),

       uVar1 = (((ushort)iVar3 & 0xf000) - *param_1) + 0x1000,

       uVar4 = (ulonglong)CONCAT22((short)((uint)iVar3 >> 0x10),uVar1), 0x2fff < uVar1)) ||

      (iVar3 = (int)(*(double *)(param_2 + 0x30) * DAT_1403502f0),

      uVar1 = ((~(ushort)iVar3 & 0xf000) - param_1[1]) + 0x1000,

      uVar4 = (ulonglong)CONCAT22((short)((uint)iVar3 >> 0x10),uVar1), 0x2fff < uVar1)) ||

     ((iVar3 = (int)(*(double *)(param_2 + 0x38) * DAT_1403502f0),

      uVar1 = (((ushort)iVar3 & 0xf000) - param_1[2]) + 0x1000,

      uVar4 = (ulonglong)CONCAT22((short)((uint)iVar3 >> 0x10),uVar1), 0x2fff < uVar1 ||

      (iVar3 = (int)(*(double *)(param_2 + 0x40) * DAT_1403502f0),

      uVar1 = ((~(ushort)iVar3 & 0xf000) - param_1[3]) + 0x1000,

      uVar4 = (ulonglong)CONCAT22((short)((uint)iVar3 >> 0x10),uVar1), 0x2fff < uVar1)))) {

    return uVar4 & 0xffffffffffffff00;

  }

  if (param_3 == '\0') {

    uVar4 = 0xffff8000;

    if ((((param_1[4] != -0x8000) || (param_1[5] != -0x8000)) &&

        ((*(double *)(param_2 + 0x18) != 0.0 || (*(double *)(param_2 + 0x20) != 0.0)))) &&

       (uVar2 = (uint)(*(double *)(param_2 + 0x18) * DAT_140350300), uVar4 = (ulonglong)uVar2,

       0x2fff < (ushort)((-0x8000 - (short)uVar2) - param_1[4]))) {

      iVar3 = (int)(*(double *)(param_2 + 0x20) * DAT_140350300);

      return (ulonglong)

             CONCAT31((int3)((uint)iVar3 >> 8),

                      (ushort)((-0x8000 - (short)iVar3) - param_1[5]) < 0x3000);

    }

  }

  return CONCAT71((int7)(uVar4 >> 8),1);

}




