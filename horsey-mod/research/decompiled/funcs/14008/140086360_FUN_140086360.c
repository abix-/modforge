// Address: 0x140086360
// Ghidra name: FUN_140086360
// ============ 0x140086360 FUN_140086360 (size=189) ============


void FUN_140086360(byte *param_1)



{

  ulonglong uVar1;

  byte bVar2;

  byte *pbVar3;

  byte *pbVar4;

  byte *pbVar5;

  ulonglong uVar6;

  byte *pbVar7;

  

  uVar1 = *(ulonglong *)(param_1 + 0x18);

  pbVar5 = (byte *)0x0;

  pbVar4 = param_1;

  if (0xf < uVar1) {

    pbVar4 = *(byte **)param_1;

  }

  bVar2 = *pbVar4;

  pbVar7 = pbVar5;

  if (bVar2 != 0) {

    do {

      uVar6 = (ulonglong)bVar2;

      pbVar3 = pbVar4;

      if ((&DAT_14030ad90)[(uint)(byte)(&DAT_14030ad90)[uVar6] + ((int)pbVar7 + 0x10) * 0x10] != 0)

      {

        pbVar3 = pbVar5;

      }

      pbVar4 = pbVar4 + 1;

      bVar2 = *pbVar4;

      pbVar5 = pbVar3;

      pbVar7 = (byte *)(ulonglong)

                       (byte)(&DAT_14030ad90)

                             [(uint)(byte)(&DAT_14030ad90)[uVar6] + ((int)pbVar7 + 0x10) * 0x10];

    } while (bVar2 != 0);

    if (pbVar3 != (byte *)0x0) {

      pbVar4 = param_1;

      if (0xf < uVar1) {

        pbVar4 = *(byte **)param_1;

      }

      uVar6 = (longlong)pbVar3 - (longlong)pbVar4;

      if (*(ulonglong *)(param_1 + 0x10) < uVar6) {

        FUN_140076790(param_1,uVar6 - *(ulonglong *)(param_1 + 0x10),0);

        return;

      }

      *(ulonglong *)(param_1 + 0x10) = uVar6;

      if (0xf < uVar1) {

        param_1 = *(byte **)param_1;

      }

      param_1[uVar6] = 0;

      return;

    }

  }

  return;

}




