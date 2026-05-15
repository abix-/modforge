// Address: 0x140278dc0
// Ghidra name: FUN_140278dc0
// ============ 0x140278dc0 FUN_140278dc0 (size=363) ============


void FUN_140278dc0(longlong param_1,undefined8 param_2,longlong param_3)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  float local_18;

  float local_14;

  float local_10;

  

  if (*(char *)(param_1 + 0x2b) != '\0') {

    bVar1 = *(byte *)(param_3 + 8);

    uVar5 = (bVar1 & 0x3fc) << 6 | (uint)*(byte *)(param_3 + 5);

    uVar6 = (*(byte *)(param_3 + 9) & 0x3fc) << 6 | (uint)*(byte *)(param_3 + 6);

    uVar4 = (*(byte *)(param_3 + 10) & 0x3fc) << 6 | (uint)*(byte *)(param_3 + 7);

    iVar2 = (uVar4 - 0x2000) * 0x1b8;

    if ((bVar1 & 1) == 0) {

      iVar2 = (uVar4 - 0x2000) * 2000;

    }

    iVar3 = (uVar5 - 0x2000) * 0x1b8;

    if ((bVar1 & 2) == 0) {

      iVar3 = (uVar5 - 0x2000) * 2000;

    }

    local_18 = ((float)((uint)((float)iVar2 * DAT_14037f31c) ^ DAT_14039cac0) * DAT_14039ca50) /

               DAT_140304c34;

    iVar2 = (uVar6 - 0x2000) * 0x1b8;

    if ((*(byte *)(param_3 + 9) & 2) == 0) {

      iVar2 = (uVar6 - 0x2000) * 2000;

    }

    local_14 = ((float)iVar3 * DAT_14037f31c * DAT_14039ca50) / DAT_140304c34;

    local_10 = ((float)iVar2 * DAT_14037f31c * DAT_14039ca50) / DAT_140304c34;

    FUN_14015afd0(*(undefined8 *)(param_1 + 0x10),param_2,2,*(undefined8 *)(param_1 + 0x10),

                  &local_18,3);

  }

  return;

}




