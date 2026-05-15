// Address: 0x14022db10
// Ghidra name: FUN_14022db10
// ============ 0x14022db10 FUN_14022db10 (size=294) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_14022db10(char *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  char cVar2;

  int iVar3;

  ulonglong uVar4;

  char *pcVar5;

  uint uVar6;

  uint uVar7;

  undefined1 *puVar8;

  uint uVar9;

  char *pcVar10;

  char *pcVar11;

  uint local_res18 [2];

  undefined4 local_res20 [2];

  undefined1 auStack_48 [32];

  

  puVar8 = auStack_48;

  uVar9 = 0;

  local_res20[0] = 0;

  local_res18[0] = 0;

  (*DAT_1403fdcf0)(8,local_res20,0,local_res18);

  uVar1 = (ulonglong)local_res18[0] * 2;

  if (uVar1 < 0x80) {

    uVar4 = uVar1 + 0xf;

    if (uVar4 <= uVar1) {

      uVar4 = 0xffffffffffffff0;

    }

    puVar8 = auStack_48 + -(uVar4 & 0xfffffffffffffff0);

    pcVar5 = &stack0xffffffffffffffd8 + -(uVar4 & 0xfffffffffffffff0);

  }

  else {

    pcVar5 = (char *)FUN_1401841f0(uVar1);

  }

  if (pcVar5 == (char *)0x0) {

    return 0;

  }

  *(undefined8 *)(puVar8 + -8) = 0x14022dbb6;

  iVar3 = (*DAT_1403fdcf0)(8,local_res20,pcVar5,local_res18);

  if (iVar3 == 0) {

    *(undefined8 *)(puVar8 + -8) = 0x14022dbc5;

    FUN_14022dc40(param_1,param_2);

  }

  else {

    uVar7 = (uint)param_2;

    if (local_res18[0] - 1 <= param_2) {

      uVar7 = local_res18[0] - 1;

    }

    uVar6 = 0;

    if (uVar7 != 0) {

      pcVar10 = pcVar5;

      pcVar11 = param_1;

      do {

        cVar2 = *pcVar10;

        if (cVar2 == '\0') {

          uVar9 = uVar6;

          cVar2 = ',';

        }

        else if (cVar2 == '-') {

          cVar2 = '_';

        }

        *pcVar11 = cVar2;

        uVar6 = uVar6 + 1;

        pcVar11 = pcVar11 + 1;

        pcVar10 = pcVar10 + 2;

      } while (uVar6 < uVar7);

    }

    param_1[uVar9] = '\0';

  }

  if (0x7f < uVar1) {

    *(undefined8 *)(puVar8 + -8) = 0x14022dc25;

    FUN_1401841e0(pcVar5);

  }

  return 1;

}




