// Address: 0x140226db0
// Ghidra name: FUN_140226db0
// ============ 0x140226db0 FUN_140226db0 (size=177) ============


void FUN_140226db0(longlong *param_1,longlong param_2,int *param_3,undefined4 *param_4)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_48;

  undefined4 local_44;

  int local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined8 local_34;

  undefined1 local_28 [8];

  int local_20;

  undefined4 local_1c;

  

  iVar1 = *(int *)(param_2 + 0xb8);

  if (((iVar1 == 0x1d) || (iVar1 == 0x3b)) || (iVar1 == 0x77)) {

    uVar2 = 0x3e9;

    iVar1 = (iVar1 + 1) * 1000;

  }

  else {

    uVar2 = 1;

  }

  *param_3 = iVar1;

  *param_4 = uVar2;

  if (param_1 != (longlong *)0x0) {

    local_48 = *(undefined4 *)(param_2 + 0xac);

    local_44 = *(undefined4 *)(param_2 + 0xb0);

    local_40 = *param_3;

    local_3c = *param_4;

    local_34 = 0;

    local_38 = 0x1c;

    iVar1 = (**(code **)(*param_1 + 0x48))(param_1,&local_48,local_28,0);

    if (-1 < iVar1) {

      *param_3 = local_20;

      *param_4 = local_1c;

    }

  }

  return;

}




