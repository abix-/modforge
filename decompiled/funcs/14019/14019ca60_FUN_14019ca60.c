// Address: 0x14019ca60
// Ghidra name: FUN_14019ca60
// ============ 0x14019ca60 FUN_14019ca60 (size=218) ============


void FUN_14019ca60(short *param_1,byte *param_2)



{

  byte bVar1;

  byte bVar2;

  sbyte sVar3;

  int iVar4;

  ushort uVar5;

  int iVar6;

  byte *pbVar7;

  

  iVar6 = 0;

  pbVar7 = param_2;

  do {

    bVar1 = *pbVar7;

    *param_1 = 0;

    if (bVar1 != 0xff) {

      bVar2 = param_2[(ulonglong)bVar1 + 0x400];

      bVar1 = param_2[(ulonglong)bVar1 + 0x500];

      uVar5 = bVar2 & 0xf;

      if (((bVar2 & 0xf) != 0) && ((ushort)(bVar1 + uVar5) < 10)) {

        sVar3 = (sbyte)uVar5;

        iVar4 = (int)(iVar6 << (bVar1 & 0x1f) & 0x1ffU) >> (9U - sVar3 & 0x1f);

        if (iVar4 < 1 << (sVar3 - 1U & 0x1f)) {

          iVar4 = iVar4 + (1 - (1 << sVar3));

        }

        if (iVar4 + 0x80U < 0x100) {

          *param_1 = ((short)iVar4 * 0x10 + (ushort)(bVar2 >> 4)) * 0x10 + uVar5 + (ushort)bVar1;

        }

      }

    }

    iVar6 = iVar6 + 1;

    pbVar7 = pbVar7 + 1;

    param_1 = param_1 + 1;

  } while (iVar6 < 0x200);

  return;

}




