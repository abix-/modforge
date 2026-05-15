// Address: 0x1401cb0d0
// Ghidra name: FUN_1401cb0d0
// ============ 0x1401cb0d0 FUN_1401cb0d0 (size=118) ============


void FUN_1401cb0d0(longlong param_1,int param_2,int param_3,undefined8 param_4,undefined4 param_5,

                  char param_6)



{

  ulonglong uVar1;

  ulonglong uVar2;

  bool bVar3;

  undefined8 local_48 [2];

  undefined4 local_38;

  int local_34;

  int local_30;

  

  bVar3 = param_2 != param_3;

  if (bVar3) {

    local_38 = param_5;

    local_48[0] = 0;

    local_48[1] = param_4;

    local_34 = param_2;

    local_30 = param_3;

  }

  uVar1 = (ulonglong)bVar3;

  uVar2 = uVar1;

  if (param_6 != '\0') {

    uVar2 = (ulonglong)(bVar3 + 1);

    local_48[uVar1 * 4] = 2;

    local_48[uVar1 * 4 + 1] = param_4;

  }

  if ((int)uVar2 != 0) {

    (**(code **)(**(longlong **)(param_1 + 0x120) + 0xd0))

              (*(longlong **)(param_1 + 0x120),uVar2,local_48);

  }

  return;

}




