// Address: 0x1400d8e00
// Ghidra name: FUN_1400d8e00
// ============ 0x1400d8e00 FUN_1400d8e00 (size=511) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400d8e00(char *param_1)



{

  int iVar1;

  size_t sVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  undefined4 local_res10 [6];

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 local_10;

  

  local_res10[0] = 0;

  local_18 = 0;

  local_10 = 0;

  local_28 = 0;

  uStack_20 = 0;

  sVar2 = strlen(param_1);

  FUN_140027e30(&local_28,param_1,sVar2);

  piVar3 = (int *)FUN_1400c4a10(&local_28,local_res10);

  if (piVar3 == (int *)0x0) {

    FUN_1400c4340("Can\'t load file %s",param_1);

  }

  else {

    iVar1 = *piVar3;

    if ((iVar1 == 100) || (iVar1 - 0x65U < 2)) {

      DAT_1403f3a20 = piVar3[1];

      piVar5 = piVar3 + 2;

      DAT_1403da90c = 0x3f000000;

      if (iVar1 == 0x66) {

        DAT_1403da90c = piVar3[2];

        piVar5 = piVar3 + 3;

      }

      DAT_1403f3a24 = *piVar5;

      piVar4 = piVar5 + 3;

      DAT_1403f3a28 = piVar5[1];

      DAT_1403f3a2c = piVar5[2];

      if (100 < iVar1) {

        DAT_1403f3a30 = piVar5[3];

        piVar4 = piVar5 + 4;

      }

      DAT_1403f3a34 = *piVar4;

      DAT_1403f3a38 = piVar4[1];

      DAT_1403f3a3c = piVar4[2];

      DAT_1403f3a40 = piVar4[3];

      _DAT_1403f3a44 = piVar4[4];

      DAT_1403f3a48 = piVar4[5];

      DAT_1403f3a4c = piVar4[6];

      DAT_1403f3a50 = piVar4[7];

      _DAT_1403f3a54 = piVar4[8];

      DAT_1403f3a58 = (char)piVar4[9] != '\0';

      DAT_1403f3a5c = *(undefined4 *)((longlong)piVar4 + 0x25);

      DAT_1403f3a60 = *(undefined4 *)((longlong)piVar4 + 0x29);

      DAT_1403f3a64 = *(undefined4 *)((longlong)piVar4 + 0x2d);

      DAT_1403f3a68 = *(undefined4 *)((longlong)piVar4 + 0x31);

      DAT_1403f3a6c = *(undefined4 *)((longlong)piVar4 + 0x35);

      DAT_1403f3a70 = *(undefined4 *)((longlong)piVar4 + 0x39);

      DAT_1403f3a74 = *(undefined4 *)((longlong)piVar4 + 0x3d);

      DAT_1403f3a78 = *(undefined4 *)((longlong)piVar4 + 0x41);

      if (100 < iVar1) {

        DAT_1403f3a7c = *(undefined4 *)((longlong)piVar4 + 0x45);

        DAT_1403f3a80 = *(undefined4 *)((longlong)piVar4 + 0x49);

      }

      FUN_1400c4de0(piVar3);

      return 1;

    }

  }

  return 0;

}




