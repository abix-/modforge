// Address: 0x1401829a0
// Ghidra name: FUN_1401829a0
// ============ 0x1401829a0 FUN_1401829a0 (size=421) ============


ulonglong FUN_1401829a0(undefined8 *param_1,uint param_2,undefined2 param_3)



{

  char cVar1;

  ushort uVar2;

  ulonglong uVar3;

  ushort uVar4;

  int iVar5;

  uint local_res8 [2];

  

  if (param_1 != (undefined8 *)0x0) {

    uVar2 = FUN_1401818e0(param_3);

    cVar1 = FUN_1401aaff0(*param_1,(uint)uVar2 << 0x10 | param_2,local_res8);

    if (cVar1 != '\0') {

LAB_140182b3f:

      return (ulonglong)local_res8[0];

    }

    if (uVar2 != 0) {

      uVar4 = uVar2 & 0x2000;

      iVar5 = (uVar4 != 0) + 1;

      do {

        if ((((((uVar2 & 4) != 0) && ((uVar4 | 4) != uVar2)) &&

             (cVar1 = FUN_1401aaff0(*param_1,(uint)(uVar4 | 4) << 0x10 | param_2,local_res8),

             cVar1 != '\0')) ||

            ((((uVar2 & 0x4003) == 0x4003 && ((uVar4 | 0x4003) != uVar2)) &&

             (cVar1 = FUN_1401aaff0(*param_1,(uint)(uVar4 | 0x4003) << 0x10 | param_2,local_res8),

             cVar1 != '\0')))) ||

           (((((uVar2 & 0x4000) != 0 && ((uVar4 | 0x4000) != uVar2)) &&

             (cVar1 = FUN_1401aaff0(*param_1,(uint)(uVar4 | 0x4000) << 0x10 | param_2,local_res8),

             cVar1 != '\0')) ||

            (((((uVar2 & 3) != 0 && ((uVar4 | 3) != uVar2)) &&

              (cVar1 = FUN_1401aaff0(*param_1,(uint)(uVar4 | 3) << 0x10 | param_2,local_res8),

              cVar1 != '\0')) ||

             (cVar1 = FUN_1401aaff0(*param_1,(uint)uVar4 << 0x10 | param_2,local_res8),

             cVar1 != '\0')))))) goto LAB_140182b3f;

        uVar4 = 0;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

    }

  }

  uVar3 = FUN_140181a10(param_2,param_3);

  return uVar3;

}




