// Address: 0x1400ebcd0
// Ghidra name: FUN_1400ebcd0
// ============ 0x1400ebcd0 FUN_1400ebcd0 (size=832) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400ebcd0(longlong *param_1,int param_2)



{

  byte *pbVar1;

  uint uVar2;

  uint uVar3;

  byte *pbVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  

  if (param_2 != 0) {

    pbVar1 = (byte *)*param_1;

    if (pbVar1 < (byte *)param_1[1]) {

      pbVar4 = pbVar1 + 1;

      uVar5 = (uint)*pbVar1;

      *param_1 = (longlong)pbVar4;

      uVar2 = uVar5 & 0xf;

      if (pbVar4 < (byte *)param_1[1]) {

        uVar3 = (uint)*pbVar4;

        *param_1 = (longlong)(pbVar1 + 2);

      }

      else {

        uVar3 = 0;

      }

    }

    else {

      uVar5 = 0;

      uVar2 = 0;

      uVar3 = 0;

    }

    uVar5 = uVar5 * 0x100 + uVar3;

    if (uVar5 != (uVar5 / 0x1f) * 0x1f) {

      _DAT_1403f4c40 = "bad zlib header";

      return 0;

    }

    if ((uVar3 & 0x20) != 0) {

      _DAT_1403f4c40 = "no preset dict";

      return 0;

    }

    if (uVar2 != 8) {

      _DAT_1403f4c40 = "bad compression";

      return 0;

    }

  }

  param_1[2] = 0;

  do {

    iVar6 = (int)param_1[2];

    if (iVar6 < 1) {

      uVar5 = *(uint *)((longlong)param_1 + 0x14);

      iVar7 = iVar6;

      do {

        pbVar1 = (byte *)*param_1;

        if (pbVar1 < (byte *)param_1[1]) {

          uVar2 = (uint)*pbVar1;

          *param_1 = (longlong)(pbVar1 + 1);

        }

        else {

          uVar2 = 0;

        }

        iVar6 = iVar7 + 8;

        uVar5 = uVar5 | uVar2 << ((byte)iVar7 & 0x1f);

        *(int *)(param_1 + 2) = iVar6;

        *(uint *)((longlong)param_1 + 0x14) = uVar5;

        iVar7 = iVar6;

      } while (iVar6 < 0x19);

    }

    uVar5 = *(uint *)((longlong)param_1 + 0x14);

    iVar7 = iVar6 + -1;

    *(int *)(param_1 + 2) = iVar7;

    uVar2 = uVar5 >> 1;

    *(uint *)((longlong)param_1 + 0x14) = uVar2;

    if (iVar7 < 2) {

      iVar6 = iVar6 + 7;

      do {

        iVar7 = iVar6;

        pbVar1 = (byte *)*param_1;

        if (pbVar1 < (byte *)param_1[1]) {

          uVar3 = (uint)*pbVar1;

          *param_1 = (longlong)(pbVar1 + 1);

        }

        else {

          uVar3 = 0;

        }

        *(int *)(param_1 + 2) = iVar7;

        uVar2 = uVar3 << ((char)iVar7 - 8U & 0x1f) | uVar2;

        *(uint *)((longlong)param_1 + 0x14) = uVar2;

        iVar6 = iVar7 + 8;

      } while (iVar7 < 0x19);

    }

    *(uint *)((longlong)param_1 + 0x14) = uVar2 >> 2;

    *(int *)(param_1 + 2) = iVar7 + -2;

    uVar2 = uVar2 & 3;

    if (uVar2 == 0) {

      iVar6 = FUN_1400ebb00(param_1);

    }

    else {

      if (uVar2 == 3) {

        return 0;

      }

      if (uVar2 == 1) {

        if (DAT_1403f4d8f == '\0') {

          _DAT_1403f4c50 = _DAT_1403102a0;

          uRam00000001403f4c58 = _UNK_1403102a8;

          _DAT_1403f4d70 = 0x5050505;

          _DAT_1403f4c60 = _DAT_1403102a0;

          uRam00000001403f4c68 = _UNK_1403102a8;

          _DAT_1403f4d74 = 0x5050505;

          _DAT_1403f4c70 = _DAT_1403102a0;

          uRam00000001403f4c78 = _UNK_1403102a8;

          _DAT_1403f4d78 = 0x5050505;

          _DAT_1403f4c80 = _DAT_1403102a0;

          uRam00000001403f4c88 = _UNK_1403102a8;

          _DAT_1403f4d7c = 0x5050505;

          _DAT_1403f4c90 = _DAT_1403102a0;

          uRam00000001403f4c98 = _UNK_1403102a8;

          _DAT_1403f4d80 = 0x5050505;

          _DAT_1403f4ca0 = _DAT_1403102a0;

          uRam00000001403f4ca8 = _UNK_1403102a8;

          _DAT_1403f4d84 = 0x5050505;

          _DAT_1403f4cb0 = _DAT_1403102a0;

          uRam00000001403f4cb8 = _UNK_1403102a8;

          _DAT_1403f4d88 = 0x5050505;

          _DAT_1403f4cc0 = _DAT_1403102a0;

          uRam00000001403f4cc8 = _UNK_1403102a8;

          _DAT_1403f4d8c = 0x5050505;

          _DAT_1403f4cd0 = _DAT_1403102a0;

          uRam00000001403f4cd8 = _UNK_1403102a8;

          _DAT_1403f4d68 = 0x8080808;

          _DAT_1403f4ce0 = _DAT_1403102b0;

          uRam00000001403f4ce8 = _UNK_1403102b8;

          _DAT_1403f4d6c = 0x8080808;

          _DAT_1403f4cf0 = _DAT_1403102b0;

          uRam00000001403f4cf8 = _UNK_1403102b8;

          _DAT_1403f4d00 = _DAT_1403102b0;

          uRam00000001403f4d08 = _UNK_1403102b8;

          _DAT_1403f4d10 = _DAT_1403102b0;

          uRam00000001403f4d18 = _UNK_1403102b8;

          _DAT_1403f4d20 = _DAT_1403102b0;

          uRam00000001403f4d28 = _UNK_1403102b8;

          _DAT_1403f4d30 = _DAT_1403102b0;

          uRam00000001403f4d38 = _UNK_1403102b8;

          _DAT_1403f4d40 = _DAT_1403102b0;

          uRam00000001403f4d48 = _UNK_1403102b8;

          _DAT_1403f4d50 = _DAT_140310290;

          uRam00000001403f4d58 = _UNK_140310298;

          _DAT_1403f4d60 = _DAT_140310290;

        }

        iVar6 = FUN_1400f03f0((longlong)param_1 + 0x34,&DAT_1403f4c50,0x120);

        if (iVar6 == 0) {

          return 0;

        }

        iVar6 = FUN_1400f03f0(param_1 + 0x103,&DAT_1403f4d70,0x20);

      }

      else {

        iVar6 = FUN_1400e6a30(param_1);

      }

      if (iVar6 == 0) {

        return 0;

      }

      iVar6 = FUN_1400eaad0(param_1);

    }

    if (iVar6 == 0) {

      return 0;

    }

  } while (((DAT_1403ffc00 == 0) || (param_1[3] - param_1[4] < 0x10001)) && ((uVar5 & 1) == 0));

  return 1;

}




