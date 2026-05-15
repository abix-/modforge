// Address: 0x140263170
// Ghidra name: FUN_140263170
// ============ 0x140263170 FUN_140263170 (size=177) ============


undefined8 FUN_140263170(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  uint uVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  ulonglong local_48;

  undefined8 local_40;

  undefined *local_38;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined8 local_24;

  undefined4 local_1c;

  undefined8 local_18;

  

  uVar1 = FUN_140137850(param_2);

  if (uVar1 == 0) {

    return 0;

  }

  puVar3 = param_1;

  if ((uVar1 & 2) == 0) {

    if ((uVar1 & 8) == 0) {

      FUN_14012e850("Unsupported GPU backend");

      return 0;

    }

    puVar3 = param_1 + 2;

  }

  local_24 = 0;

  local_18 = 0;

  local_40 = *puVar3;

  local_48 = (ulonglong)*(uint *)(puVar3 + 1);

  local_30 = *(undefined4 *)((longlong)puVar3 + 0xc);

  local_38 = &DAT_1403424a4;

  local_28 = *(undefined4 *)(param_1 + 4);

  local_1c = *(undefined4 *)((longlong)param_1 + 0x24);

  local_2c = param_3;

  uVar2 = FUN_140135420(param_2,&local_48);

  return uVar2;

}




