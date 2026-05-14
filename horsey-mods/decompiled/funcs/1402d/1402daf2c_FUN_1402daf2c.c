// Address: 0x1402daf2c
// Ghidra name: FUN_1402daf2c
// ============ 0x1402daf2c FUN_1402daf2c (size=356) ============


uint FUN_1402daf2c(uint param_1,FILE *param_2,longlong param_3)



{

  char **ppcVar1;

  bool bVar2;

  uint uVar3;

  undefined *puVar4;

  undefined *puVar5;

  undefined1 auStack_48 [32];

  undefined8 local_28;

  longlong local_20;

  undefined1 *local_18;

  

  local_18 = auStack_48;

  local_20 = param_3;

  if (param_2 == (FILE *)0x0) {

    *(undefined1 *)(param_3 + 0x30) = 1;

    *(undefined4 *)(param_3 + 0x2c) = 0x16;

    local_28 = 0;

    local_18 = auStack_48;

    FUN_1402cd39c(0,0,0,0);

    return 0xffffffff;

  }

  FUN_1402e1710(param_2);

  if ((*(uint *)((longlong)&param_2->_base + 4) >> 0xc & 1) == 0) {

    uVar3 = _fileno(param_2);

    if (uVar3 + 2 < 2) {

      puVar5 = &DAT_1403e8ea0;

    }

    else {

      puVar5 = (undefined *)

               ((&DAT_1403ff160)[(longlong)(int)uVar3 >> 6] + (ulonglong)(uVar3 & 0x3f) * 0x48);

    }

    puVar4 = &DAT_1403e8ea0;

    if (puVar5[0x39] == '\0') {

      if (1 < uVar3 + 2) {

        puVar4 = (undefined *)

                 ((&DAT_1403ff160)[(longlong)(int)uVar3 >> 6] + (ulonglong)(uVar3 & 0x3f) * 0x48);

      }

      if ((puVar4[0x3d] & 1) == 0) goto LAB_1402db015;

    }

    bVar2 = false;

  }

  else {

LAB_1402db015:

    bVar2 = true;

  }

  if (bVar2) {

    ppcVar1 = &param_2->_base;

    *(int *)ppcVar1 = *(int *)ppcVar1 + -1;

    if (*(int *)ppcVar1 < 0) {

      param_1 = FUN_1402eebd8(param_1,param_2,param_3);

    }

    else {

      *param_2->_ptr = (char)param_1;

      param_2->_ptr = param_2->_ptr + 1;

      param_1 = param_1 & 0xff;

    }

    FUN_1402e171c(param_2);

  }

  else {

    *(undefined1 *)(param_3 + 0x30) = 1;

    *(undefined4 *)(param_3 + 0x2c) = 0x16;

    local_28 = 0;

    FUN_1402cd39c(0,0,0,0);

    FUN_1402f8d60(local_18,0x1402db055);

    param_1 = 0xffffffff;

  }

  return param_1;

}




