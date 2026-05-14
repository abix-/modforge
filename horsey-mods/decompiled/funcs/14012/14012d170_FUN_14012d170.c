// Address: 0x14012d170
// Ghidra name: FUN_14012d170
// ============ 0x14012d170 FUN_14012d170 (size=107) ============


ulonglong FUN_14012d170(longlong param_1,undefined8 param_2,ulonglong param_3,undefined4 *param_4)



{

  ulonglong uVar1;

  

  uVar1 = FUN_14012d060(param_1,*(undefined8 *)(param_1 + 8),param_2,param_3);

  if ((uVar1 < param_3) && (*(longlong *)(param_1 + 0x10) == *(longlong *)(param_1 + 8))) {

    FUN_14012e850("Memory buffer is full");

    *param_4 = 1;

  }

  return uVar1;

}




