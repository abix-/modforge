// Address: 0x14018b080
// Ghidra name: FUN_14018b080
// ============ 0x14018b080 FUN_14018b080 (size=176) ============


undefined8 FUN_14018b080(undefined8 param_1,longlong param_2,ulonglong param_3)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  FUN_14018a480(param_2);

  if (*(uint *)(param_2 + 4) < param_3) {

    param_3 = (ulonglong)*(uint *)(param_2 + 4);

  }

  if (param_3 != 0) {

    lVar1 = FUN_1401841f0(param_3);

    *(longlong *)(param_2 + 0x10) = lVar1;

    if (lVar1 == 0) {

      return 0xffffffff;

    }

    lVar1 = *(longlong *)(param_2 + 8);

    lVar2 = FUN_14012cb40(param_1,lVar1,0);

    if (lVar2 != lVar1) {

      return 0xfffffffe;

    }

    uVar3 = FUN_14012c730(param_1,*(undefined8 *)(param_2 + 0x10),param_3);

    *(undefined8 *)(param_2 + 0x18) = uVar3;

  }

  return 0;

}




