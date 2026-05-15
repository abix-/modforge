// Address: 0x1401a31e0
// Ghidra name: FUN_1401a31e0
// ============ 0x1401a31e0 FUN_1401a31e0 (size=117) ============


undefined8 FUN_1401a31e0(ulonglong *param_1)



{

  byte bVar1;

  byte bVar2;

  byte *pbVar3;

  byte *pbVar4;

  undefined8 uVar5;

  byte *pbVar6;

  uint uVar7;

  

  pbVar3 = (byte *)param_1[1];

  pbVar4 = (byte *)*param_1;

  if (pbVar4 < pbVar3) {

    bVar1 = *pbVar4;

    pbVar6 = pbVar4 + 1;

    *param_1 = (ulonglong)pbVar6;

    if (pbVar6 < pbVar3) {

      bVar2 = *pbVar6;

      *param_1 = (ulonglong)(pbVar4 + 2);

      if (pbVar4 + 2 < pbVar3) {

        uVar7 = (uint)bVar1 * 0x100 + (uint)bVar2;

        if (((uVar7 == (uVar7 / 0x1f) * 0x1f) && ((bVar2 & 0x20) == 0)) && ((bVar1 & 0xf) == 8)) {

          return 1;

        }

      }

    }

  }

  uVar5 = FUN_14019f050("Corrupt PNG");

  return uVar5;

}




