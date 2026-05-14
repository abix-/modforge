// Address: 0x140269330
// Ghidra name: FUN_140269330
// ============ 0x140269330 FUN_140269330 (size=62) ============


void FUN_140269330(longlong param_1,undefined1 *param_2,undefined2 param_3,byte param_4,byte param_5

                  ,short param_6)



{

  undefined1 uVar1;

  char cVar2;

  

  if ((param_4 == 0) && (param_6 == 0)) {

    if ((*(short *)(param_1 + 0x20) == 0x57e) && (*(short *)(param_1 + 0x22) == 0x2019)) {

      cVar2 = '\0';

    }

    else {

      cVar2 = '\x01';

    }

    *param_2 = 0;

    param_2[1] = cVar2;

    uVar1 = 0x40;

    if (cVar2 == '\0') {

      uVar1 = 1;

    }

    param_2[2] = uVar1;

    param_2[3] = 0x40;

    return;

  }

  *param_2 = (char)param_3;

  param_2[3] = (char)param_6;

  param_2[1] = (byte)((ushort)param_3 >> 8) & 1 | param_4;

  param_2[2] = (byte)((ushort)param_6 >> 8) & 0x80 | param_5;

  return;

}




