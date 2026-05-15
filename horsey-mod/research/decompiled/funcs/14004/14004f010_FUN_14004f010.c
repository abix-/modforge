// Address: 0x14004f010
// Ghidra name: FUN_14004f010
// ============ 0x14004f010 FUN_14004f010 (size=143) ============


undefined8 FUN_14004f010(ulonglong param_1)



{

  longlong lVar1;

  uint uVar2;

  ulonglong uVar3;

  longlong lVar4;

  uint uVar5;

  

  if (param_1 != 0) {

    lVar1 = *(longlong *)(DAT_1403ea2a8 + 0x88);

    uVar3 = param_1 * 0x40000 + ~param_1;

    uVar5 = *(int *)(DAT_1403ea2a8 + 0x90) - 1;

    uVar3 = (uVar3 >> 0x1f ^ uVar3) * 0x15;

    uVar3 = (uVar3 >> 0xb ^ uVar3) * 0x41;

    uVar2 = ((uint)(uVar3 >> 0x16) ^ (uint)uVar3) & uVar5;

    lVar4 = (longlong)(int)uVar2;

    uVar3 = *(ulonglong *)(lVar1 + lVar4 * 0x10);

    while (uVar3 != 0) {

      if (uVar3 == param_1) {

        return *(undefined8 *)(lVar1 + 8 + lVar4 * 0x10);

      }

      uVar2 = uVar2 + 1 & uVar5;

      lVar4 = (longlong)(int)uVar2;

      uVar3 = *(ulonglong *)(lVar1 + lVar4 * 0x10);

    }

  }

  return 0;

}




