// Address: 0x1400f33e0
// Ghidra name: FUN_1400f33e0
// ============ 0x1400f33e0 FUN_1400f33e0 (size=280) ============


int FUN_1400f33e0(byte *param_1,undefined8 param_2,undefined4 param_3)



{

  byte *pbVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = 0;

  pbVar1 = param_1;

  while( true ) {

    iVar2 = FUN_1400f40d0(param_1);

    if (iVar2 == 0) {

      if (((((*param_1 != 0x74) || (param_1[1] != 0x74)) || (param_1[2] != 99)) ||

          ((param_1[3] != 0x66 ||

           ((iVar2 = (uint)param_1[5] * 0x10000 + (uint)param_1[6] * 0x100 +

                     (uint)param_1[4] * 0x1000000 + (uint)param_1[7], iVar2 != 0x10000 &&

            (iVar2 != 0x20000)))))) ||

         ((int)((((uint)param_1[9] + (uint)param_1[8] * 0x100) * 0x100 + (uint)param_1[10]) * 0x100

               + (uint)param_1[0xb]) <= iVar4)) {

        return -1;

      }

      iVar2 = (uint)pbVar1[0xc] * 0x1000000 + (uint)pbVar1[0xd] * 0x10000 +

              (uint)pbVar1[0xe] * 0x100 + (uint)pbVar1[0xf];

    }

    else {

      iVar2 = -(uint)(iVar4 != 0);

    }

    if (iVar2 < 0) {

      return iVar2;

    }

    iVar3 = FUN_1400f4140(param_1,iVar2,param_2,param_3);

    if (iVar3 != 0) break;

    iVar4 = iVar4 + 1;

    pbVar1 = pbVar1 + 0xe;

  }

  return iVar2;

}




