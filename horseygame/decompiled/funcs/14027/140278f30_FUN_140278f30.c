// Address: 0x140278f30
// Ghidra name: FUN_140278f30
// ============ 0x140278f30 FUN_140278f30 (size=463) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140278f30(longlong param_1,undefined8 param_2,longlong param_3)



{

  byte bVar1;

  byte bVar2;

  ushort uVar3;

  undefined8 uVar4;

  byte bVar5;

  float local_18;

  float local_14;

  float local_10;

  

  if (5 < *(byte *)(param_3 + 0x1c)) {

    bVar1 = *(byte *)(param_3 + 10);

    if (*(char *)(param_1 + 0x2a) == '\x05') {

      bVar2 = bVar1 >> 3;

      bVar1 = bVar1 >> 2;

    }

    else {

      bVar2 = bVar1 >> 1;

    }

    FUN_14015ad00(*(undefined8 *)(param_1 + 0x10),param_2,9,~bVar2 & 1);

    uVar4 = 0xffff8000;

    if ((~bVar1 & 1) != 0) {

      uVar4 = 0xffff7fff;

    }

    FUN_14015aab0(*(undefined8 *)(param_1 + 0x10),param_2,4,uVar4);

    FUN_140279910(*(undefined8 *)(param_1 + 0x10),param_2,param_1 + 0x62,0,

                  *(undefined1 *)(param_3 + 5));

    FUN_140279910(*(undefined8 *)(param_1 + 0x10),param_2,param_1 + 0x6a,1,

                  *(undefined1 *)(param_3 + 6));

    if (*(char *)(param_1 + 0x2b) != '\0') {

      bVar1 = *(byte *)(param_3 + 10);

      uVar3 = (ushort)*(byte *)(param_3 + 9) << 2;

      if (*(char *)(param_1 + 0x2a) == '\x05') {

        bVar5 = 2;

        uVar3 = uVar3 & 0xfffb | (ushort)(bVar1 >> 5 & 6);

        bVar2 = bVar1 >> 3 & 2;

      }

      else {

        bVar5 = 3;

        uVar3 = uVar3 | bVar1 >> 6;

        bVar2 = bVar1 >> 2 & 3;

      }

      local_18 = (float)((uint)((float)(int)(((uint)*(byte *)(param_3 + 7) << 2 | (uint)bVar2) -

                                            0x200) / DAT_140304c38) ^ DAT_14039cac0) *

                 _DAT_1403553cc;

      local_14 = ((float)(int)(uVar3 - 0x200) / DAT_140304c38) * _DAT_1403553cc;

      local_10 = ((float)(int)(((uint)(bVar1 >> 4 & bVar5) | (uint)*(byte *)(param_3 + 8) << 2) -

                              0x200) / DAT_140304c38) * _DAT_1403553cc;

      FUN_14015afd0(*(undefined8 *)(param_1 + 0x10),param_2,3,*(undefined8 *)(param_1 + 0x10),

                    &local_18,3);

    }

  }

  return;

}




