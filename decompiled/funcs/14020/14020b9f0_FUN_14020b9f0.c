// Address: 0x14020b9f0
// Ghidra name: FUN_14020b9f0
// ============ 0x14020b9f0 FUN_14020b9f0 (size=277) ============


ulonglong FUN_14020b9f0(short *param_1,byte param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined8 uVar3;

  

  uVar1 = (ulonglong)param_2;

  uVar2 = uVar1;

  if ((((((&DAT_1403fd1e2)[uVar1 * 0x18] == '\0') ||

        (uVar2 = (ulonglong)((ushort)(&DAT_1403fd1d4)[uVar1 * 0xc] & 0xfffffbff),

        (short)((ushort)(&DAT_1403fd1d4)[uVar1 * 0xc] & 0xfffffbff) != param_1[6])) ||

       (uVar2 = (ulonglong)(uint)(int)*param_1,

       0x2fff < ((int)*(short *)(&DAT_1403fd1d8 + uVar1 * 0x18) - (int)*param_1) + 0x1000U)) ||

      ((uVar2 = (ulonglong)(uint)(int)param_1[1],

       0x2fff < (~(int)*(short *)(&DAT_1403fd1da + uVar1 * 0x18) - (int)param_1[1]) + 0x1000U ||

       (uVar2 = (ulonglong)(uint)(int)param_1[2],

       0x2fff < ((int)*(short *)(&DAT_1403fd1dc + uVar1 * 0x18) - (int)param_1[2]) + 0x1000U)))) ||

     (uVar2 = (ulonglong)(uint)(int)param_1[3],

     0x2fff < (~(int)*(short *)(&DAT_1403fd1de + uVar1 * 0x18) - (int)param_1[3]) + 0x1000U)) {

    return uVar2 & 0xffffffffffffff00;

  }

  uVar3 = 0xffff8000;

  if ((param_1[4] != -0x8000) || (param_1[5] != -0x8000)) {

    uVar3 = 0;

    if ((((&DAT_1403fd1d6)[uVar1 * 0x18] == 0) || ((&DAT_1403fd1d7)[uVar1 * 0x18] == '\0')) &&

       (0x2fff < ((uint)(byte)(&DAT_1403fd1d6)[uVar1 * 0x18] * 0x101 - (int)param_1[4]) - 0x8000)) {

      return (ulonglong)

             CONCAT31((int3)(char)((ushort)param_1[5] >> 8),

                      ((uint)(byte)(&DAT_1403fd1d7)[uVar1 * 0x18] * 0x101 - (int)param_1[5]) -

                      0x8000 < 0x3000);

    }

  }

  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);

}




