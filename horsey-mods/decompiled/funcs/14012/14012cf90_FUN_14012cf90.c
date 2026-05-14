// Address: 0x14012cf90
// Ghidra name: FUN_14012cf90
// ============ 0x14012cf90 FUN_14012cf90 (size=130) ============


undefined8 FUN_14012cf90(longlong param_1,undefined8 param_2,ulonglong param_3,undefined4 *param_4)



{

  char cVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  lVar3 = *(longlong *)(param_1 + 0x10);

  if ((ulonglong)(*(longlong *)(param_1 + 0x18) - lVar3) < param_3) {

    if (((ulonglong)(*(longlong *)(param_1 + 0x28) - lVar3) < param_3) &&

       (cVar1 = FUN_14012cea0(param_1,param_3), cVar1 == '\0')) {

      *param_4 = 1;

      return 0;

    }

    lVar3 = *(longlong *)(param_1 + 0x10);

    *(ulonglong *)(param_1 + 0x18) = lVar3 + param_3;

  }

  uVar2 = FUN_14012d060(param_1 + 8,lVar3,param_2,param_3);

  return uVar2;

}




