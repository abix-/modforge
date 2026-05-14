// Address: 0x140289cb0
// Ghidra name: FUN_140289cb0
// ============ 0x140289cb0 FUN_140289cb0 (size=98) ============


bool FUN_140289cb0(undefined8 *param_1)



{

  int iVar1;

  bool bVar2;

  int local_res8 [2];

  longlong *local_res10 [3];

  

  local_res10[0] = (longlong *)0x0;

  bVar2 = false;

  iVar1 = (**(code **)*param_1)(param_1,&DAT_140380c88,local_res10);

  if (-1 < iVar1) {

    iVar1 = (**(code **)(*local_res10[0] + 0x18))(local_res10[0],local_res8);

    if (-1 < iVar1) {

      bVar2 = local_res8[0] == 1;

    }

  }

  (**(code **)(*local_res10[0] + 0x10))();

  return bVar2;

}




