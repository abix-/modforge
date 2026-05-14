// Address: 0x14005bad0
// Ghidra name: FUN_14005bad0
// ============ 0x14005bad0 FUN_14005bad0 (size=228) ============


undefined8 * FUN_14005bad0(undefined8 *param_1)



{

  ulonglong uVar1;

  char *pcVar2;

  undefined8 *puVar3;

  ulonglong uVar4;

  

  FUN_1400c9420();

  *param_1 = &PTR_FUN_140306090;

  uVar1 = param_1[6];

  if (uVar1 < 7) {

    uVar4 = 0x7fffffffffffffff;

    if (uVar1 <= 0x7fffffffffffffff - (uVar1 >> 1)) {

      uVar1 = uVar1 + (uVar1 >> 1);

      uVar4 = 0xf;

      if (0xf < uVar1) {

        uVar4 = uVar1;

      }

    }

    pcVar2 = (char *)FUN_1400285e0(uVar4 + 1);

    param_1[5] = 7;

    param_1[6] = uVar4;

    *(undefined4 *)pcVar2 = s_GifLand_140306150._0_4_;

    *(undefined2 *)(pcVar2 + 4) = s_GifLand_140306150._4_2_;

    pcVar2[6] = s_GifLand_140306150[6];

    pcVar2[7] = '\0';

    param_1[3] = pcVar2;

  }

  else {

    puVar3 = param_1 + 3;

    if (0xf < uVar1) {

      puVar3 = (undefined8 *)param_1[3];

    }

    param_1[5] = 7;

    FUN_1402f8e20(puVar3,"GifLand",7);

    *(undefined1 *)((longlong)puVar3 + 7) = 0;

  }

  FUN_1400c9f10(param_1);

  return param_1;

}




