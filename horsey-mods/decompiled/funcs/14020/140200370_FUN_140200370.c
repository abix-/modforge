// Address: 0x140200370
// Ghidra name: FUN_140200370
// ============ 0x140200370 FUN_140200370 (size=586) ============


undefined8 FUN_140200370(undefined8 *param_1,longlong param_2,undefined4 param_3)



{

  uint uVar1;

  char cVar2;

  undefined8 uVar3;

  longlong *plVar4;

  char *pcVar5;

  

  cVar2 = FUN_1401489c0(param_2);

  if (cVar2 == '\0') {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar3;

  }

  uVar1 = *(uint *)(param_2 + 4);

  if ((((uVar1 == 0) || ((uVar1 & 0xf0000000) != 0x10000000)) || ((uVar1 & 0xff00) < 0x800)) ||

     (0x2000 < (uVar1 & 0xff00))) {

    pcVar5 = "Unsupported surface format";

  }

  else {

    FUN_140155450(param_1,param_3);

    if (*(int *)(param_1 + 0x41) == 0x120005a0) {

      *(undefined1 *)((longlong)param_1 + 0x114) = 1;

      plVar4 = (longlong *)FUN_1401841a0(1,0x10);

      if (plVar4 == (longlong *)0x0) {

        return 0;

      }

      *plVar4 = param_2;

      plVar4[1] = param_2;

      *param_1 = &LAB_140202630;

      param_1[1] = FUN_140200800;

      param_1[0xe] = FUN_140200340;

      param_1[0xf] = &LAB_140202540;

      param_1[0x10] = &LAB_1402007b0;

      param_1[0x11] = &LAB_140200310;

      param_1[3] = FUN_1402005c0;

      param_1[0x12] = FUN_140202560;

      param_1[0x15] = &LAB_140200860;

      param_1[0x16] = _guard_check_icall;

      param_1[0x17] = &LAB_140202510;

      param_1[4] = FUN_140018e60;

      param_1[5] = FUN_140018e60;

      param_1[6] = FUN_140200a10;

      param_1[7] = FUN_140200a10;

      param_1[8] = FUN_140200b00;

      param_1[9] = FUN_1402008a0;

      param_1[10] = FUN_140200940;

      param_1[0xb] = FUN_140200cf0;

      param_1[0xc] = _guard_check_icall;

      param_1[0xd] = FUN_140201890;

      param_1[0x18] = FUN_1402017e0;

      param_1[0x19] = &LAB_1402017c0;

      param_1[0x1a] = &LAB_1402007f0;

      param_1[0x1b] = FUN_1402007c0;

      param_1[0x5c] = plVar4;

      param_1[0x20] = PTR_s_software_1403e4c48;

      FUN_1402022d0(param_1,*(undefined4 *)(param_2 + 4));

      return 1;

    }

    pcVar5 = "Unsupported output colorspace";

  }

  uVar3 = FUN_14012e850(pcVar5);

  return uVar3;

}




