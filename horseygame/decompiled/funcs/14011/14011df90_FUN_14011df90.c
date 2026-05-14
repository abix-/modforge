// Address: 0x14011df90
// Ghidra name: FUN_14011df90
// ============ 0x14011df90 FUN_14011df90 (size=225) ============


undefined1

FUN_14011df90(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)



{

  undefined1 uVar1;

  uint uVar2;

  undefined1 *local_c8 [2];

  undefined1 local_b8 [168];

  

  local_c8[0] = local_b8;

  FUN_140124b00();

  uVar2 = (*(code *)PTR_FUN_1403de8b8)(local_b8,0x80,param_4,&stack0x00000028);

  if ((-1 < (int)uVar2) && (0x7f < uVar2)) {

    local_c8[0] = (undefined1 *)0x0;

    uVar2 = (*(code *)PTR_FUN_1403de8b0)(local_c8,param_4,&stack0x00000028);

  }

  uVar1 = 0;

  if (-1 < (int)uVar2) {

    uVar1 = (*(code *)PTR_FUN_1403dea28)(param_1,param_2,param_3,&DAT_14039bf30,local_c8[0]);

  }

  if (local_c8[0] != local_b8) {

    (*(code *)PTR_FUN_1403de4e0)();

  }

  return uVar1;

}




