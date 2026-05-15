// Address: 0x1401fd560
// Ghidra name: FUN_1401fd560
// ============ 0x1401fd560 FUN_1401fd560 (size=275) ============


void FUN_1401fd560(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined4 *param_8)



{

  undefined4 local_68;

  undefined8 local_64;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined8 local_30;

  undefined8 local_28;

  

  if (*(longlong *)(param_1 + 0x710) != 0) {

    (*DAT_1403fcf10)(*(undefined8 *)(param_1 + 0x698));

    *(undefined8 *)(param_1 + 0x710) = 0;

  }

  local_64 = 0;

  local_5c = 0;

  local_28 = 1;

  local_50 = *param_8;

  local_40 = param_7;

  local_68 = 0x2d;

  local_4c = param_6;

  local_48 = 0xffffffffffffffff;

  local_38 = 1;

  local_30 = 1;

  local_58 = param_2;

  local_54 = param_3;

  (*DAT_1403fcf18)(*(undefined8 *)(param_1 + 0x698),param_4,param_5,0,0,0,0,0,1,&local_68);

  *param_8 = param_6;

  return;

}




